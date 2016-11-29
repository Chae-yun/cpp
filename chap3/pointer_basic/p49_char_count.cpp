#include <iostream>
using namespace std;
int main(){
	char *pMessage = "welcome to korea";

	for (int i = 0;; i++){
		if (*(pMessage + i) == NULL){ //#define NULL 0    그리고 '\0'도 같다 이스케이프 시퀀스이기 때문에 2글자 아니고 1글자로 취급! "말고 '이거
			cout << "count=" << i << endl;
			break;
		}
	}

	
	/*int i;
	for (i = 0; *(pMessage + i) != NULL; i++);
	cout << "count=" << i << endl;*/ //이런 방법도 있다

	return 0;
}