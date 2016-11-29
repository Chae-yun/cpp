#include <iostream>
using namespace std;
int main(){
	//1+(2*2)+(3*3)+...+(10*10)
	int sum = 1;
	for (int i = 2; i <= 10; i++){
		sum += pow(i, 2);
	}
	cout << "ÃÑ ÇÕ : " << sum << endl;
	return 0;
}