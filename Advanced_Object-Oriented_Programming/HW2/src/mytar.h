#ifndef __MYTAR_H__
#define __MYTAR_H__
#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int AsciiToNum(unsigned char c) {
  return c - 48;
}

unsigned char* CheckNUL(unsigned char* currentPtr, char* end) {
  unsigned char* checkNulPtr = currentPtr;
  unsigned char* resultPtr = currentPtr;
  for(; checkNulPtr >= (unsigned char*)end; checkNulPtr--) {
    if((*checkNulPtr) == 0 || (*checkNulPtr) == ' ' )
      resultPtr = checkNulPtr - 1;
  }
  return resultPtr;
}

unsigned long long int OctToDec(char* data) {

    size_t field_size = 12;
    unsigned char* currentPtr = (unsigned char*) data + field_size;
    unsigned long long int sum = 0;
    unsigned long long int currentMultiplier = 1;

    currentPtr = CheckNUL(currentPtr, data);
    for(; currentPtr >= (unsigned char*)data; currentPtr--) {
      sum += AsciiToNum(*currentPtr) * currentMultiplier;
      currentMultiplier *= 8;
    }
    return sum;
}

struct TarHeader {
  char filename[100]; //0~99
  char filemode[8];   //100~107
  char userid[8];     //108~115
  char groupid[8];    //116~123
  char filesize[12];  //124~135
  char mtime[12];     //136~147
  char checksum[8];   //148~155
  char type;          //156
  char lname[100];    //157~256
  /* USTAR Section */
  char USTAR_id[6];   //257~262
  char USTAR_ver[2];  //263~264
  char username[32];  //265~296
  char groupname[32]; //297~328
  char devmajor[8];   //329~336
  char devminor[8];   //337~344
  char prefix[155];   //345~499
  char pad[12];       //500~511

  bool isUSTAR() {
    return (memcmp("ustar", USTAR_id, 5) == 0);
  }

  size_t getFileSize() {
    return OctToDec(filesize);
  }
  int size; //file size in decimal
  char time_str[40];
};

class tarfile {
private:
  static const int name_len = 1024;
  char filename[name_len];
  fstream file;
  vector<TarHeader> databuffer;
  int tar_total_bytes;
  int check_header();
public:
  tarfile();
  tarfile( const char *name );
  ~tarfile();
  void openfile();
  void check_format();
  void print_result();
  void encoding();
  void close();
};

#endif
