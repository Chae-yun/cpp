#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream org("filecopy.cpp");

	if (!org.is_open())
		cout << "원본 파일이 없습니다." << endl;

	//ofstream des("b.dat");
	ofstream des("b.dat", ios_base::out | ios_base::trunc | ios_base::binary);
	//바이너리로 열면 더 빨라진다
	//근데 엔터가 이상해..........

	char buf[1024];

	for (;;){
		org.read(buf, 1024);
		if (org.gcount() == 0)break;
		//읽은 사이즈가 0이면 멈춰라
		des.write(buf, org.gcount());
		//여기도 1024하면 이상한 쓰레기나오니까 gcount()
	}

	org.close();
	des.close();

	return 0;
}