#include <iostream>
using namespace std;
int main(){
	int iCode;

	iCode = 'A';
	cout << (char)iCode << " -> " << iCode << endl;
	iCode = 'B';
	cout << (char)iCode << " -> " << iCode << endl;
	iCode = 'C';
	cout << (char)iCode << " -> " << iCode << endl;

	char cCode = 'a';
	cout << cCode << " -> " << (int)cCode << endl;
	cCode = 'b';
	cout << cCode << " -> " << (int)cCode << endl;
	cCode = 'c';
	cout << cCode << " -> " << (int)cCode << endl;
	
	//또다른 표현
	iCode = 'A';
	cout << (char)iCode << " -> " << iCode << endl;
	iCode = iCode+1;
	cout << (char)iCode << " -> " << iCode << endl;
	iCode = iCode+1;
	cout << (char)iCode << " -> " << iCode << endl;

	cCode = 'a';
	cout << cCode << " -> " << (int)cCode << endl;
	cCode = cCode+1;
	cout << cCode << " -> " << (int)cCode << endl;
	cCode = cCode+1;
	cout << cCode << " -> " << (int)cCode << endl;

	return 0;
}