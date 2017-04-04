#include <iostream>

using namespace std;

class SchoolMember{
	char* number;
	char* name;

public:
	SchoolMember(){}
	SchoolMember(char* number, char* name){
		this->number = number;
		this->name = name;
	}
	virtual ~SchoolMember(){
	}
	char* GetNum(){
		return number;
	}
	char* GetName(){
		return name;
	}
	virtual void Print() = 0;
};

class Teacher : public SchoolMember{
	char* subject;
	int year;

public:
	Teacher(){}
	Teacher(char* number, char* name, char* subject, int year) : SchoolMember(number, name){
		this->subject = subject;
		this->year = year;
	}
	virtual ~Teacher(){
	}
	void Print(){
		printf("%-8s%-10s%-15s%3d\n", SchoolMember::GetNum(), SchoolMember::GetName(), subject, year);
	}
};

class Student : public SchoolMember{
	char* major;
	int grade;

public:
	Student(){}
	Student(char* number, char* name, char* major, int grade) : SchoolMember(number, name){
		this->major = major;
		this->grade = grade;
	}
	virtual ~Student(){
	}
	void Print(){
		if (!strcmp(major, "S"))
			major = "Software";
		else if (!strcmp(major, "D"))
			major = "Design";

		if (grade > 3)
			printf("%-8s%-10s%-15sError<%d>\n", SchoolMember::GetNum(), SchoolMember::GetName(), major, grade);
		else
			printf("%-8s%-10s%-15s%3d\n", SchoolMember::GetNum(), SchoolMember::GetName(), major, grade);
	}
};

class Admin : public SchoolMember{
	char* work;
	int year;

public:
	Admin(){}
	Admin(char* number, char* name, char* work, int year) : SchoolMember(number, name){
		this->work = work;
		this->year = year;
	}
	virtual ~Admin(){
	}
	void Print(){
		printf("%-8s%-10s%-15s%3d\n", SchoolMember::GetNum(), SchoolMember::GetName(), work, year);
	}
};

int main(){
	char* data[7][4] = { { "MS1", "강서연", "D", "10" }, { "MS2", "고주원", "S", "7" },
	{ "MT1", "양민서", "영어", "21" }, { "MA1", "송하준", "정보보호", "11" }, { "MT2", "방서현", "운영체제", "25" },
	{ "MS3", "김예준", "S", "3" }, { "MT3", "이지민", "컴퓨터그래픽", "8" } };

	const int size = sizeof(data) / sizeof(data[0]);
	SchoolMember* pSm[size];
	char TSA[3] = { 'T', 'S', 'A' };

	for (int i = 0; i < size; i++){
		if (data[i][0][1]=='T'){
			pSm[i] = new Teacher(data[i][0], data[i][1], data[i][2], atoi(data[i][3]));
		}
		else if (data[i][0][1] == 'S'){
			pSm[i] = new Student(data[i][0], data[i][1], data[i][2], atoi(data[i][3]));
		}
		else if (data[i][0][1] == 'A'){
			pSm[i] = new Admin(data[i][0], data[i][1], data[i][2], atoi(data[i][3]));
		}
	}
	for (int i = 0; i < size; i++){
		if (i == 0)
			cout << "Teacher********************************************************\n";
		else if (i == 1)
			cout << "Student********************************************************\n";
		else if (i == 2)
			cout << "Administrator**************************************************\n";
		for (int j = 0; j < size; j++){
			if (data[j][0][1] == TSA[i])
				pSm[j]->Print();
		}
		cout << "***************************************************************\n";
		if (i == 2)break;
	}
	for (int i = 0; i < size; i++){
		delete pSm[i];
	}

	return 0;
}