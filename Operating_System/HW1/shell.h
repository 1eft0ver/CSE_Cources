#ifndef __SHELL_H__
#define __SHELL_H__

typedef int File_Descriptor;
typedef int bool;

enum
{
  LINE_SIZE = 100,
  Command_Size = 20
};

void start();
void Reset_Settings();
void type_prompt();
bool read_command();
void Create_Pipe( char *pipe1[Command_Size], char *pipe2[Command_Size], bool In_Redirecton, File_Descriptor Input_Path, bool Out_Redirecton, File_Descriptor Output_Path );


#endif