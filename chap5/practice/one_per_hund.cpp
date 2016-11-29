#include <iostream>
using namespace std;
int main(){
	double sum = 0;
	for (int i = 1; i <= 100; i++){
		sum += (double)1 / i; //1.0/iµµ µÇ°í i¸¦ ´õºí·Î Áàµµ µÊ??
	}
	cout << "ÃÑ ÇÕ : " << sum << endl;
	return 0;
}