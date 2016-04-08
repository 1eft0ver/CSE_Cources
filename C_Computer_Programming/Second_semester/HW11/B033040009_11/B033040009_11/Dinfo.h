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
	string number;
	string name;
	bool sex;
	int age;
	string mail;
	string pic;
	string address;
	Dinfo (){
		next = NULL;
		prev = NULL;
	};

	Dinfo (string _number, string _name, bool _sex, int _age,string _mail, string _pic, string _address){
		next = NULL;
		prev = NULL;
		number = _number;
		name = _name;
		sex = _sex;
		age = _age;
		mail = _mail;
		pic = _pic;
		address = _address;
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