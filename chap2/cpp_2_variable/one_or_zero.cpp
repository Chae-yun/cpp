#include <iostream>
/*#define TRUE 1
#define FALSE 0*/
using namespace std;
int main(){
	bool flag = true;
	while (true){
		if (flag == true){
			cout << "2113\n";
			flag = false;
		}
		else{
			cout << "¾çÃ¤À±\n";
			flag = true;
		}
	}
	return 0;
}