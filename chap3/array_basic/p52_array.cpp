#include <iostream>
using namespace std;
int main(){
	//int nArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //이래도 됨 굳이 사이즈 안써도 OK
	int nArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int nArray[10] = { 0, }; //이러면 다 0으로 초기화 ','없어도 되는데??
	//그러나 다 1로 하거나 이럴라면 위 방법 안되고 반복문 돌려야 함
	//int nArray[10]; //자체적으로 초기화는 안시켜줌
	int count = sizeof(nArray) / sizeof(int);
	
	for (int i = 0; i < count; i++)
		cout << i << " : " << nArray[i] << endl;

	cout << sizeof(nArray) << endl;

	return 0;
}