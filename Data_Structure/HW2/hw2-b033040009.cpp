/*
Author�G���y�� B033040009
Date�GOct. 19, 2015
Purpose�G�HC++�s�@�@�ӡu���X�v���O (set class)�A�Ϩ��i��u�ݩ�v�B�u�p���v�B�u�涰�v�B�u�t���v�B�u�]�t�v�����عB��C
*/

#include <iostream>
#include <string>
using namespace std;

class TSet{
	public:
		TSet();                                         //Constructor
		TSet(string);                                   //�㦳��l�Ȫ�Construtor
		~TSet();                                        //Destructor
		void SetValue(int, int);                        //�]�wset���Y�Ӧr���ƭȪ��禡
		int GetValue(int);                              //���oset���Y�Ӧr���ƭȪ��禡
		bool in(char);                                  //�T�{�Y�Ӧr���O�_�s�b���禡
		TSet operator+(const TSet& s);                  //overload +
		TSet operator*(const TSet& s);                  //overload *
		TSet operator-(const TSet& s);                  //overload -
		bool operator>=(const TSet& s);                 //overload >=

	private:
		int value[256];                                 //�̷��D�حn�D�A�ϥΪ��׬�256���}�C�Ӫ��ܤ@�Ӷ��X
};

void TSet::SetValue(int index, int val){
	value[index] = val;
}

int TSet::GetValue(int index){
	return value[index];
}
bool TSet::in(char x){
    if(value[x] == 1)
        return true;
    else
        return false;
}

TSet::~TSet(){
}

TSet::TSet(){                                                   //�S��������ȮɡA�w�]��l�Ȭ�������0
	for(int i = 0 ; i < 256 ; ++i)
	value[i] = 0;
}

TSet::TSet(string str){
	for(int i = 0 ; i < 256 ; ++i)
	value[i] = 0;
	for(int j = 0 ; j < str.size() ; ++j)
	value[str[j]] = 1;
}

TSet TSet::operator+(const TSet& s){
	TSet temp;
	for(int i = 0 ; i < 256 ; ++i)
		if(value[i] == 1 || s.value[i] == 1)
		temp.SetValue(i, 1);
	return temp;
}

TSet TSet::operator*(const TSet& s){
    TSet temp;
	for(int i = 0 ; i < 256 ; ++i)
		if(value[i] == 1 && s.value[i] == 1)
		temp.SetValue(i, 1);
	return temp;
}

TSet TSet::operator-(const TSet& s){
    TSet temp;
	for(int i = 0 ; i < 256 ; ++i)
		if(value[i] == 1 && s.value[i] == 0)
		temp.SetValue(i, 1);
	return temp;
}

bool TSet::operator>=(const TSet& s){
	int i = 0;
	while(s.value[i]<= value[i] && i < 256)
        ++i;
    if( i == 256)
    return true;
    else
    return false;
}

std::ostream& operator<<(std::ostream& os, TSet& s){            //overload�w��TSet�ɡAostream��<<�B��l������覡 - ��X���X���e
    string temp;
    for(int i = 0 ; i < 256 ; ++i)
        if(s.GetValue(i) == 1)
            temp += i;
    os << temp;
    return os;
}

int main(){
    int n = 0;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        char x;


        string temp_A, temp_B;
        cin.ignore();
        getline(cin, temp_A);
        getline(cin, temp_B);
        //cin >> temp_A >> temp_B;
        x = getchar();
        TSet A(temp_A), B(temp_B);


        TSet C, D, E, F;
        C = A + B;
        D = A * B;
        E = A - B;
        F = B - A;

        cout << "Test Case " << (i+1) << ":" << endl;                       //�̷��D�حn�D�榡�A�N���G��X
        cout << "A: {" << A << "}" << endl;
        cout << "B: {" << B << "}" << endl;
        cout << "A+B: {" << C << "}" << endl;
        cout << "A*B: {" << D << "}" << endl;
        cout << "A-B: {" << E << "}" << endl;
        cout << "B-A: {" << F << "}" << endl;
        if(A >= B)
            cout << "A contains B" <<endl;
        else
            cout << "A does not contain B" << endl;

        if(B >= A)
            cout << "B contains A" << endl;
        else
            cout << "B does not contain A" << endl;

        if(A.in(x))
            cout << "'" << x << "' is in A" << endl;
        else
            cout << "'" << x << "' is not in A" << endl;

        if(B.in(x))
            cout << "'" << x << "' is in B" << endl;
        else
            cout << "'" << x << "' is not in B" << endl;
        cout << endl;
    }
}