#include <iostream>
using namespace std;
int main(){
	for (int i = 1; i <= 10; i++){
		if (i == 5)
			//break; //4까지만 찍고 끝남
			continue; //5빼고 찍는다 //컨틴뉴를 마지막에 쓴다면 있으나 없으나 동일

		cout << i << endl;
	}
	return 0;
}