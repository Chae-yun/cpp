#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��ȭ�� Ŭ���� ����
class Phone{
protected:
	char szNumber[20];

public:
	Phone(){ szNumber[0] = 0; } //��ȭ�� Ŭ���� ������
	Phone(char* pszNumber){ strcpy(szNumber, pszNumber); }
	virtual ~Phone(){ cout << "Phone �Ҹ���" << endl; }

public:
	void SetNumber(char* pNo){ strcpy(szNumber, pNo); }
	char* GetNumber(){ return szNumber; }
	
	//��ȭ�� �Ŵ� ��� ����
	void Call(){ cout << GetNumber() << "�� ��ȭ�� �Ǵ�" << endl; }

	//��ȭ���� ��ǰ ������ ���
	void ShowInfo(){ cout << "��ȭ��ȣ : " << GetNumber() << endl; }
};

//ī�޶� Ŭ���� ����
class Camera{
public:
	Camera(){ cout << "Camera ������" << endl; }
	virtual ~Camera(){ cout << "Camera �Ҹ���" << endl; }

public:
	//������ ��� ���
	void Shutter(){ cout << "������ ��´�" << endl; }
};

//���߻������ ��ȭ��� ī�޶� Ȯ���ϴ� �޴��� Ŭ����
class MobilePhone :public Phone, public Camera{ //���߻��
public:
	MobilePhone(){ cout << "MobilePhone ������ #1\n"; }
	MobilePhone(char* pNumber) :Phone(pNumber){
		cout << "MobilePhone ������#2\n";
	}
	virtual ~MobilePhone(){ cout << "MobilePhone �Ҹ���" << endl; }

public:
	void ShowInfo(){
		Phone::ShowInfo(); //��ȭ���� ��ǰ ���� ���
		cout << "200�鸸 ȭ�� ī�޶�!" << endl; //��ǰ ���� ���
	}
};

class SmartPhone :public Phone{ //���, ����
	Camera* ca; //����

public:
	SmartPhone(char* pNumber) :Phone(pNumber){
		cout << "SmartPhone ������\n";
	}
	virtual ~SmartPhone(){ cout << "SmartPhone �Ҹ���" << endl; }
	void Shutter(){ ca->Shutter(); }
};

class MobileDevice{ //�� �� ����
	Phone ph;
	Camera ca;

public:
	MobileDevice(char* pNumber){
		ph.SetNumber(pNumber);
		cout << "MobileDevice ������\n";
	}
	virtual ~MobileDevice(){ cout << "MobileDevice �Ҹ���" << endl; }
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