#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand((unsigned)time(0)); //void srand(unsigned int _seed)

	for (int i = 0; i < 10; i++){
		cout << i << " : ³­¼ö°ª : " << 50+(rand() % 50) << endl; //50~99
	}
	return 0;
}