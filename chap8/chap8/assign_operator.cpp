#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Student{
public:
	int nNo;
	char* szName;

	Student(){
		nNo = 0;
		szName = 0;
		cout << nNo << " �⺻ ������" << endl;
	}
	Student(int no, char* name){
		nNo = no;
		szName = new char[strlen(name) + 1]; //ȿ������ ���
		strcpy(szName, name);
		cout << nNo << " �Ű������� 2���� ������" << endl;
	}
	Student(Student& st){ //���� ������ ������ �߰��� ������ �Ͼ�� ����
		if (this != &st){
			this->nNo = st.nNo;
			this->szName = new char[strlen(st.szName) + 1];
			//Student e=e �ϸ� �Ҵ��ϴٰ� ����  szName�� ���̰� �����ϱ� �� �ѹ������� ���׾�?
			strcpy(this->szName, st.szName);
		}
		else{
			/*this->nNo = 0;
			this->szName = 0;*/
			//this();
			Student();
			//C�� this�� super�̷� �ŷ� ���ϰ� �׳� �̸� �θ���
			//�Ҹ��� �� �Ͼ�� �Ŵ� ������ ���ٿͼ� �׷���?? �ֱ׷��� �ٵ� �� ������ �Ҹ�� �����ϸ� �ȉ�
		}
	} //���� �����ֳ� if�� ó�� �� ���൵ ��

	~Student(){
		if (szName){
			cout << szName << " �Ҹ���" << endl;
			delete[] szName;
		}
		else{
			cout << "�̸� ���� �Ҹ�" << endl;
		}
	}

	void PrintStudent(){
		if (szName != NULL)
			cout << "��ȣ : " << nNo << ", �̸� : " << szName << endl;
		else
			cout << "��ȣ : " << nNo << ", �̸� ����" << endl;
	}

	Student& Copy(Student& ori){
		if (this != &ori){ //��ü�� ���ٴ� ���� �ּ�(���, ������ �ƴϾ�)�� ���ƾ� ��
			//this�� ��ü�� �ּ�, ori�� �����̱� ������ �ּҷ�
			this->nNo = ori.nNo;
			if (this->szName){
				delete[] this->szName; //[]? ��� ��?
			} //b=c���� �� ���� �ִ� �޸𸮰� �������� �ٸ� �� �����Ѵ�, �޸� ���� �߻�
			this->szName = new char[strlen(ori.szName) + 1]; //�� ���� ��������!
			strcpy(this->szName, ori.szName); //a=a�ϸ� �̹� �ٸ� ���� ����Ű�� ������ �����⿡ �����⸦ �ִ� ��
			//cout << "#############################################";
			//�ݹ��̹�� ori�� ���� ������ ��...�´� a�� ������ ����Ű�� copy�� �����鼭 ori�� �װ� a�� ���ӱ��� �׿�... �ݹ��̷��۷��� &�� �ؾ���......
		}
		return *this; //��� void�� �ص� ����� ���� copy�Ⱦ��Ÿ�
	}

	Student& operator=(Student& ori){ //������ ����� �͵� �ᱹ �Լ��� ����� �� (������ �����ε�)
		//�Ű������� &���ϸ� ���� ����, �߰��� �Ҹ��� �ع�����
		//���ϰ��� ��ü�� �����ָ� a=b=c �� �� �����̴�
		//�׸��� ���ϰ��� &�� ���� ������ a=b=c ���� ������ b=c ����� �� �Ű������� ���� ������
		cout << "�Ҵ翬���� ȣ��" << endl;
		Copy(ori);

		return *this;  //ori���ٴ� ��ü�� �Ǵ� this
		//Studenet�� �����ؾ��ϱ� ������ *this
	}
};

void a(){
	Student a(1, "������"); //�������� �Ű����� �ִ� ������ ȣ���
	a.PrintStudent();

	Student b; //�������� �⺻ ������ ȣ���
	b.PrintStudent();

	//b = a; //������� �⺻ �����͸� �̰� ��, 0110101110 �̷��� �״�� ������
	//szName�� �����ϰ� �� �׷��� �Ҹ��� �� b�� ���� �׿��� �� ������ ������� a���� �� ���α׷��� �״´�
	//b.Copy(a); //��ᵵ ��
	//b = a; //��ᵵ ��
	b.operator=(a); //�Լ� �̸��� operator=��� ������
	b.PrintStudent();
	strcpy(b.szName, "�����");
	b.PrintStudent();
	a = a;
	a.PrintStudent();

	Student c;
	c = b = a; //�Ҵ翬������ �켱������ �����ʺ��� c=(b=a)�� ����, void�� �º� �캯 Ÿ���� �� �¾�
	c.PrintStudent();

	b = c;
	b.PrintStudent();
	c.PrintStudent();
	
	cout << "------------------------------------------------" << endl;

	Student d = b; //�Ҵ翬���� ȣ���� �ȵȴ� (d��ü�� ���� ��������� ���̱� ������ �����ڸ� �������Ѵ�!, �켱������ ��� ��?)
	//�Ҵ翬���ڸ� �Ⱥҷ����� �����Ϸ��� ������ �ִ� �Ҵ� ����� ��(�Ƹ� 1:1)�� �ҷ���
	//�׷��� �׿���?? a�ϸ� �������� ��Ÿ�ӿ���, b�ϸ� ������ �ϳ� ���� ��Ÿ�ӿ���
	//Studend d(b); ���� ������ �θ����� �ҷ��� �ȴ�
	b.PrintStudent();
	d.PrintStudent();



	Student e = e;
	e.PrintStudent();

	cout << "a����^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
} //�������� ���� ��ü�� ���������̱� ������ ���α׷��� �ƴ϶� �� �Լ��� ������ �״´�

int main(){
	a();
	cout << "��������^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	return 0;
}