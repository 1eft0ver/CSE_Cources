#include <string>
#include <iostream>
using namespace std;
using namespace System;
void MarshalString ( String ^ s, string& os ) {
   using namespace Runtime::InteropServices;
   const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}



class Dinfo
{
public:
	int number;
	string name;
	bool sex;
	string mail;
	Dinfo (){
		next = NULL;
		prev = NULL;
	};

	Dinfo (int _number,string _name,bool _sex,string _mail){
		next = NULL;
		prev = NULL;
		number = _number;
		name = _name;
		sex = _sex;
		mail = _mail;
	};
	
	void setnext(Dinfo *ptr){ 
		next = ptr;
	};
	void setpre(Dinfo *ptr){ 
		prev = ptr;
	};
	Dinfo* getnext(){
		return next;
	};
	Dinfo* getpre(){
		return prev;
	};
	
private:
	Dinfo *next;
	Dinfo *prev;
};