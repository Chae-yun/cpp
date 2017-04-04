#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class Student{
	int nNo; //��ȣ
	char szName[20]; //�̸�

public:
	Student(){}
	Student(int no, char* name){
		SetData(no, name);
	}
	void SetData(int no, char* name){
		nNo = no;
		strcpy(szName, name);
	}
	//���Ͽ� �����ϴ� �Լ�
	void Save(ofstream& ofs){
		ofs << nNo << szName << endl;
		cout << "SAVE : " << nNo << ", " << szName << endl;
	}
	//���Ͽ��� �о���� �Լ�
	void Read(ifstream& ifs){
		ifs >> nNo >> szName;
		cout << "READ : " << nNo << ", " << szName << endl;
	}
	//���Ͽ� �����ϱ� ���� << ������ �ߺ�����
	friend ofstream& operator<<(ofstream& ofs, Student& student){
		cout << "<< ";
		student.Save(ofs);
		return ofs;
	}
	//���Ͽ��� �о���� ���� >> ������ �ߺ�����
	friend ifstream& operator>>(ifstream& ifs, Student& student){
		cout << ">> ";
		student.Read(ifs);
		return ifs;
	}
};

////���Ͽ� �����ϱ� ���� << ������ �ߺ�����
//ofstream& operator<<(ofstream& ofs, Student& student){
//	cout << "<<";
//	student.Save(ofs);
//	return ofs;
//}
//�Ϲ��Լ��� ���� ������ ��Ʃ��Ʈ�� ����ϴϱ� �ȿ� �־���� ģ���� ����
//�׷��� ��Ʃ��Ʈ�� ����� �� �� �ְ� ������ �Ϲ��Լ�ó�� �ȴ�.

int main(){
	Student students[3]; //�л� ��ü ����

	students[0].SetData(1, "���ϳ�"); //��ü �ʱⰪ ����
	students[1].SetData(2, "��θ�");
	students[2].SetData(3, "�輼��");

	int nCount = sizeof(students) / sizeof(Student); //�迭 ���� ���

	cout << "COUNT : " << nCount << endl;
	ofstream outfile("out3.dat"); //���� ����
	for (int i = 0; i < nCount; i++){
		//students[i].Save(outfile); //�Լ� ȣ��� ����
		outfile << students[i]; //�ߺ����ǵ� << �����ڷ� ����
	}
	outfile.close(); //���� �ݱ�

	cout << "------------------------------------------" << endl;

	ifstream infile("out3.dat"); //���� ����
	for (int i = 0; i < nCount; i++){
		//students[i].Read(infile); //�Լ� ȣ��� �б�
		infile >> students[i]; //�ߺ����ǵ� >> �����ڷ� �б�
	}
	infile.close(); //���� �ݱ�

	return 0;
}