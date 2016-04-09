#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define TRUE 1
#define FALSE 0
#define STD_INPUT 0
#define STD_OUTPUT 1
#define DEBUG(format, args...)
//#define DEBUG(format, args...) printf("[%s:%d] "format, __FILE__, __LINE__, ##args)

static char line[LINE_SIZE];
static char *process1[Command_Size], *process2[Command_Size];
static char *Output_Path, *Input_Path;
static int status = 0;
static bool SHELL_EXIT = FALSE, Out_Redirecton = FALSE, In_Redirecton = FALSE, In_Background = FALSE;

void start()
{
  printf( "\nShell start:        (Type EXIT or exit to stop)\n--------------------------------------------------\n" );
  while ( TRUE )
  {
    type_prompt();  // 以>>提示輸入指令    
    Reset_Settings(); // 重置shell設定值
    bool Is_Pipe = read_command(); //讀取並解析輸入的指令，回傳值代表是否存在pipe

    if ( SHELL_EXIT )
    {
      printf( "--------------------------------------------------\nShell stopped.\n" );
      kill( 0, 2 ); //
      //kill指令 :包含於 sys/types.h
      //int kill(pid_t pid, int sig);
      // pid > 0 : 將信號傳給process識別碼為pid的process
      // pid = 0 : 將信號傳給和目前process相同process group的所有process
      // pid = -1 : 將信號廣播傳送給系統內所有process
      // pid < 0 : 將信號傳給process識別碼為abs(pid)的所有process
      // signal 2:Interrupt from keyboard to every process in the process group of the calling process.
      break;
    }

    //
    if ( strcmp( process1[0], "cd" ) == 0 )
    {
      chdir( process1[1] ); 
      //chdir指令 : 包含於 unistd.h
      //int chdir(const char *path); 
      //成功時回傳0 錯誤時回傳-1
      continue;
    }

    if ( fork() > 0 ) //parent process
    {
      if ( !In_Background )
      {
        waitpid( -1, &status, 0 );
        //waitpid指令 :包含於 sys/wait.h
        //作用 : wait for process to change state
        //pid_t waitpid(pid_t pid, int *status, int options); 
        //pid < -1 :  等待所有process group ID與abs(pid)相同的child process
        //pid = -1 : 等待所有的child process
        //pid = 0 : 等待所有process group ID與pid相同的child process
        //pid > 0 : 等待所有ID與pid相同的child process

      }
    }

    // void Create_Pipe( char *pipe1[Command_Size], 
    //                              char *pipe2[Command_Size], 
    //                              bool In_Redirecton, 
    //                              bool Out_Redirecton, 
    //                              File_Descriptor Input_Path , 
    //                              File_Descriptor Output_Path )
    else {
      if ( Is_Pipe )
      {
        if ( Out_Redirecton ) {
          File_Descriptor fd_out = open( Output_Path, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO );
          Create_Pipe( process1, process2, FALSE, 0, TRUE, fd_out );
        }
        else if (In_Redirecton) {
          File_Descriptor fd_in = open( Input_Path, O_RDONLY );
          Create_Pipe( process1, process2, TRUE, fd_in, FALSE, 0 );
        }
        else
          Create_Pipe( process1, process2, FALSE,  0, FALSE,  0 );
      }

      else {
        if ( Out_Redirecton ) {
          File_Descriptor fd_out = open( Output_Path, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO );
          dup2( fd_out, STD_OUTPUT );
          execvp( process1[0], process1 );
          // int execvp(const char *file, char *const argv[]);
          close( fd_out );
        }
        else if ( In_Redirecton ) {
          File_Descriptor fd_in = open( Input_Path, O_RDONLY );
          dup2( fd_in, STD_INPUT );
          execvp( process1[0], process1 );
          close( fd_in );
        }
        else
          execvp( process1[0], process1 );
      }
    }
  }
}

void Reset_Settings()
{
  SHELL_EXIT = FALSE;
  Out_Redirecton = FALSE;
  In_Redirecton = FALSE;
  memset( line, 0, sizeof( line ) );
  memset( process1, 0, sizeof( process1 ) );
  memset( process2, 0, sizeof( process2 ) );
  Input_Path = NULL;
  Output_Path = NULL;
}

void type_prompt() {
  printf( ">>" );
}

bool read_command() {
  bool Is_Pipe = FALSE;  //判斷有沒有pipe ('|'字元) 
  char *parameters[Command_Size], *pch;
  int split_index  = 0;

  fgets( line, sizeof( line ), stdin ); //自stdin讀入一行指令 存入line陣列

  if ( line[strlen( line ) - 1] == '\n' ) //將換行字元替換成字串結尾空字元
    line[strlen( line ) - 1] = '\0'; 

  if ( strcmp( line, "exit" ) == 0 || strcmp( line, "EXIT" ) == 0 ) //假如輸入為EXIT或exit 離開shell
    SHELL_EXIT = TRUE;

  pch = strtok( line, " " );                                 ////////////////////////////////////////////////////
  parameters[split_index] = pch;                    //                                                               //
  split_index++;                                               //                                                               //
  while ( pch != NULL )                                    //   將指令分割 存入parameters陣列中     //
  {                                                                    //   parameters內儲存的是指向片斷          //
    pch = strtok( NULL, " " );                            //   指令開始的位置                                    //
    parameters[split_index] = pch;                  //                                                               //
    split_index++;                                             //                                                               //
  }                                                                   ////////////////////////////////////////////////////


  int pro1_start = 0, pro1_end = 0, pro2_start = 0, pro2_end = 0;
  int num_split = split_index - 1;

  int i;
  for ( i = 0; i < num_split; i++ )
  {
    if ( *parameters[i] == '|' )  {    //pipe                                      
      Is_Pipe = TRUE;                     //偵測到'|'時 代表這行指令有pipe
      if(In_Redirecton || Out_Redirecton){
        pro2_start = i + 1;
      }
      else{
      pro1_end = i;                        //以'|'為分界 '|'所在處為process1結尾 '|'下一片段為process2開頭
      pro2_start = i + 1;
      }
    }

    if ( *parameters[i] == '>' )  //Redirection : output
    {
      Out_Redirecton = TRUE;

      if ( Is_Pipe ){            //假如在此之前已經確認到pipe的存在
        pro2_end = i;       //則此處為process2的結尾
      }
      else{                        //假如在此之前沒有確認到pipe的存在
        pro1_end = i;       //則此處為process1的結尾
      }

      Output_Path = parameters[i + 1];  //輸出的路徑為當前確認到redirection處的下個片段
    }

    if ( *parameters[i] == '<' )  //Redirecton : input
    {
      In_Redirecton = TRUE;

      if ( Is_Pipe ) {           //假如在此之前已經確認到pipe的存在
        pro2_end = i;       //則此處為process2的結尾
      }
      else{                        //假如在此之前沒有確認到pipe的存在
        pro1_end = i;       //則此處為process1的結尾
      }
      Input_Path = parameters[i + 1];  //輸入的路徑為當前確認到redirection處的下個片段
    }

    if ( *parameters[i] == '&' )  //In_Background
    {
      In_Background = TRUE;

      if ( Is_Pipe )            //假如在此之前已經確認到pipe的存在
        pro2_end = i;       //則此處為process2的結尾

      else                        //假如在此之前沒有確認到pipe的存在
        pro1_end = i;       //則此處為process1的結尾
    }

    if ( i == num_split - 1 && pro2_end == 0 && !Out_Redirecton && Is_Pipe )   // 假如已經讀到指令結尾，在此之前沒有確認到redirection的存在
      pro2_end = split_index - 1;                                                                           //可是有讀取到pipe，代表此處為process2的結尾    
       
    if ( i == num_split - 1 && pro1_end == 0 && !Out_Redirecton )                     // 假如已經讀到指令結尾，在此之前沒有確認到redirection的存在，
      pro1_end = split_index - 1;                                                                           //也沒有pipe，代表此處為process1的結尾
  }

  for ( i = 0; i < pro1_end - pro1_start; i++ )    //建構出process1的可執行格式 : e.g. char* arg[] = {"ls", "-l", NULL};
    process1[i] = parameters[i + pro1_start];
  process1[pro1_end - pro1_start] = NULL;         //結尾處的NULL

  if ( Is_Pipe )  {                                                     //有pipe的話，才會有process2的存在
    for ( i = 0; i < pro2_end - pro2_start; i++ )  //建構出process2的可執行格式 : e.g. char* arg[] = {"ls", "-l", NULL};
      process2[i] = parameters[i + pro2_start];
    process2[pro2_end - pro2_start] = NULL;       //結尾處的NULL bool In_Redirecton, bool Out_Redirecton, File_Descriptor Input_Path , File_Descriptor Output_Path 
  }
  /*
for(int i = 0 ; i < pro1_end - pro1_start ; ++i) 
        printf("process1[%d]:%s\n", i, process1[i]);
for(int i = 0 ; i < pro2_end - pro2_start ; ++i) 
        printf("process2[%d]:%s\n", i, process2[i]);
*/
  return Is_Pipe;
}

  void Create_Pipe( char *pipe1[Command_Size], char *pipe2[Command_Size], bool In_Redirecton, File_Descriptor Input_Path, bool Out_Redirecton, File_Descriptor Output_Path )
{
  File_Descriptor fd[2];
  pipe( &fd[0] );
  if ( fork() == 0 )
  {
    close( STD_OUTPUT );
    dup2( fd[1], STD_OUTPUT );
    close( fd[0] );
    if ( In_Redirecton )
    {
      dup2( Input_Path, STD_INPUT );
      close( Input_Path );
      execvp( pipe1[0], pipe1 );
    }
    else
    execvp( pipe1[0], pipe1 );
  }

   else
  {
    close( STD_INPUT );
    dup2( fd[0], STD_INPUT );
    close( fd[1] );
    if ( Out_Redirecton )
    {
      dup2( Output_Path, STD_OUTPUT );
      close( Output_Path );
      execvp( pipe2[0], pipe2 );
    }
    else
    {
      execvp( pipe2[0], pipe2 );
    }
  }

}