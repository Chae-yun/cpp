#include <iostream>
using namespace std;

int main(){
	int nArray[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	int *pArray1 = nArray[0];
	//int *pArray2 = nArray; //이 이름으로 따라가려면 2번 따라가야 하기 때문에 ㄴㄴ
	//**pArray2는 또 안됨 몇 칸 건너뛰어야 할 지 모르거든 *pArray2[3]이라 해야 돼
	//int *pArray3 = &nArray[0][0];
	//int *pArray4 = &nArray[0]; //이 이름으로 따라가려면 2번 따라가야 하기 때문에 ㄴㄴ

	cout << nArray[0] << endl << nArray << endl << &nArray[0][0] << endl << &nArray[0] << endl <<*( pArray1+4);

	return 0;
}