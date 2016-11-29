#include<iostream>
using namespace std; //이걸 써주면 std:: 안써줘도 됨
/*void main(){
std::cout << "Hello\n";
std::cout << 5 << std::endl;
}*/
namespace b1{
	long a = 5;
	void funca(){
		cout << "a 출력";
	}
}

namespace b3{
	int a = 10;
	void funca(){
		cout << "b 출력";
	}
}

int main(){
	cout << b1::a; //::영역연산자
	b1::funca();
	int k;
	cin >> k;
	return 0; //int main 이기 때문에 리턴이 있어야 좋다.
	//리턴이 0이 아니면 os가 정상종료가 되지 않았다고 인식
}