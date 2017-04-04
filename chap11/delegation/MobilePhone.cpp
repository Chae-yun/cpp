#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//전화기 클래스 정의
class Phone{
protected:
	char szNumber[20];

public:
	Phone(){ szNumber[0] = 0; } //전화기 클래스 생성자
	Phone(char* pszNumber){ strcpy(szNumber, pszNumber); }
	virtual ~Phone(){ cout << "Phone 소멸자" << endl; }

public:
	void SetNumber(char* pNo){ strcpy(szNumber, pNo); }
	char* GetNumber(){ return szNumber; }
	
	//전화를 거는 기능 수행
	void Call(){ cout << GetNumber() << "로 전화를 건다" << endl; }

	//전화기의 제품 정보를 출력
	void ShowInfo(){ cout << "전화번호 : " << GetNumber() << endl; }
};

//카메라 클래스 정의
class Camera{
public:
	Camera(){ cout << "Camera 생성자" << endl; }
	virtual ~Camera(){ cout << "Camera 소멸자" << endl; }

public:
	//사진을 찍는 기능
	void Shutter(){ cout << "사진을 찍는다" << endl; }
};

//다중상속으로 전화기와 카메라를 확장하는 휴대폰 클래스
class MobilePhone :public Phone, public Camera{ //다중상속
public:
	MobilePhone(){ cout << "MobilePhone 생성자 #1\n"; }
	MobilePhone(char* pNumber) :Phone(pNumber){
		cout << "MobilePhone 생성자#2\n";
	}
	virtual ~MobilePhone(){ cout << "MobilePhone 소멸자" << endl; }

public:
	void ShowInfo(){
		Phone::ShowInfo(); //전화기의 제품 정보 출력
		cout << "200백만 화소 카메라!" << endl; //제품 정보 출력
	}
};

class SmartPhone :public Phone{ //상속, 위임
	Camera* ca; //위임

public:
	SmartPhone(char* pNumber) :Phone(pNumber){
		cout << "SmartPhone 생성자\n";
	}
	virtual ~SmartPhone(){ cout << "SmartPhone 소멸자" << endl; }
	void Shutter(){ ca->Shutter(); }
};

class MobileDevice{ //둘 다 위임
	Phone ph;
	Camera ca;

public:
	MobileDevice(char* pNumber){
		ph.SetNumber(pNumber);
		cout << "MobileDevice 생성자\n";
	}
	virtual ~MobileDevice(){ cout << "MobileDevice 소멸자" << endl; }
	void Call(){ ph.Call(); }
	void ShowInfo(){ ph.ShowInfo(); }
	void Shutter(){ ca.Shutter(); }
};

int main(){
	MobilePhone mp("02-123-4567");
	mp.Call();
	mp.ShowInfo();
	mp.Shutter();

	SmartPhone sp("010-1234-5678");
	sp.Call();
	sp.ShowInfo();
	sp.Shutter();

	MobileDevice md("010-8765-4321");
	md.Call();
	md.ShowInfo();
	md.Shutter();
}