#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(){
	char a[20];
	gets(a);
	cout << strlen(a);

	return 0;
}