#include <iostream>
#include <conio.h>
//#define p 2
using namespace std;

int main(){
	
	int p = 0;
    int now = 0;
	int pre = 0;

	char** hakbun = NULL;
	char** name = NULL;
	double* aver = NULL;
	char* title[4] = { "����", "����", "����", "c++ " };
	short** score = NULL;
	double sum_aver[5];
	short* rank = NULL;

	char** p_hakbun = NULL;
	char** p_name = NULL;
	double* p_aver = NULL;
	short** p_score = NULL;

	cout << "����������������������������������\n";
	cout << "�� ->-> ����ó��  ���α׷� <-<- ��\n";
	cout << "����������������������������������\n";

	while (true){

		int choice;
		cout << "\n�޴�\n";
		cout << "1. �Է�\n";
		cout << "2. ���\n";
		cout << "3. ����\n\n";
		cout << "���ڸ� �Է��Ͻÿ� : ";
		cin >> choice;
		cout << endl;

		switch (choice){

		case 1:

			cout << "�� ���� �Է��Ͻðڽ��ϱ�? : ";
			cin >> p;
			cout << endl << "****************************************************************************" << endl;

			if (pre != 0){
				p_hakbun = new char*[pre];
				p_name = new char*[pre];
				p_aver = new double[pre];
				p_score = new short*[pre];

				for (int i = 0; i < pre; i++){
					p_hakbun[i] = new char[5];
					p_name[i] = new char[11];
					p_score[i] = new short[5];
				}

				for (int i = 0; i < pre; i++){
					p_hakbun[i] = hakbun[i];
					p_name[i] = name[i];
					p_aver[i] = aver[i];
					for (int j = 0; j < 5; j++){
						p_score[i][j] = score[i][j];
					}
				}
				//���� �Ǵµ� �ؿ��� �ȵ�
				for (int i = 0; i < pre; i++){
					delete[] hakbun[i];
					delete[] name[i];
				}

				for (int i = 0; i < pre + 1; i++){
					delete[] score[i];
				}

				delete[] hakbun;
				delete[] name;
				delete[] score;
				delete[] aver;
				cout << "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n";
				hakbun = new char*[p + pre];
				name = new char*[p + pre];
				aver = new double[p + pre];
				score = new short*[p + pre + 1];
				rank = new short[p + pre];

				for (int i = 0; i < p + pre; i++){
					hakbun[i] = new char[5];
					name[i] = new char[11];
				}

				for (int i = 0; i < p + pre + 1; i++){
					score[i] = new short[5];
				}

				if (pre != 0){
					for (int i = 0; i < pre; i++){
						hakbun[i] = p_hakbun[i];
						name[i] = p_name[i];
						aver[i] = p_aver[i];
						for (int j = 0; j < 5; j++){
							score[i][j] = p_score[i][j];
						}
					}
				}

				for (int i = 0; i < pre; i++){
					delete[] p_hakbun[i];
					delete[] p_name[i];
					delete[] p_score[i];
				}

				delete[] p_hakbun;
				delete[] p_name;
				delete[] p_score;
				delete[] p_aver;
			}
			else{
				hakbun = new char*[p + pre];
				name = new char*[p + pre];
				aver = new double[p + pre];
				score = new short*[p + pre + 1];
				rank = new short[p + pre];

				for (int i = 0; i < p + pre; i++){
					hakbun[i] = new char[5];
					name[i] = new char[11];
				}

				for (int i = 0; i < p + pre + 1; i++){
					score[i] = new short[5];
				}
			}

			now = 0;

			for (int i = 0; i < 5; i++)
				score[p + pre][i] = 0;
			
			for (int i = 0; i < p + pre; i++)
				rank[i] = 1;

			sum_aver[4] = 0;

			for (int i = pre; i < p + pre; i++){
				//while (true){
				score[i][4] = 0;

				cout << "\n�й��� �Է��Ͻÿ� (0000 �̸� ����) : ";
				cin >> hakbun[i];

				if (!strcmp(hakbun[i], "0000")){
					cout << endl << "�����մϴ�" << endl << endl;
					cout << "****************************************************************************" << endl;
					now = i;
					break;
				}

				cout << "�̸��� �Է��Ͻÿ�                  : ";
				cin >> name[i];

				cout << endl;

				int j;

				for (j = 0; j < 4; j++){
					do{
						cout << title[j] << " ������ �Է��Ͻÿ� (0~100)     : ";
						cin >> score[i][j];
					} while (score[i][j] < 0 || score[i][j] > 100);
					score[i][4] += score[i][j];
				}

				cout << endl;

				aver[i] = (double)score[i][4] / 4;

				now++;
				cout << "****************************************************************************" << endl;
			}

			pre += p;

			for (int i = 0; i < pre; i++){
				for (int j = 0; j < 4; j++)
					score[pre][j] += score[i][j];
				score[pre][4] += score[i][4];
				sum_aver[4] += aver[i];
			}

			for (int i = 0; i < now - 1; i++){
				for (int j = i + 1; j < now; j++){
					if (score[i][4] > score[j][4])
						rank[j]++;
					else if (score[i][4] < score[j][4])
						rank[i]++;
				}
			}

			cout << "�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.";
			_getch();

			break;


		case 2:

			if (now == 0){
				cout << "�Է��Ͻ� �л��� �� �� �����ϴ�\n\n";
			}
			else{
				for (int i = 0; i < 4; i++)
					sum_aver[i] = (double)score[pre][i] / pre;
				sum_aver[4] /= pre;

				cout << "****************************************************************************" << endl << endl;

				cout << "�й�            �̸�   ����    ����    ����     c++    ����      ���  ����" << endl;
				cout << "����������������������������������������������������������������������������" << endl;

				for (int i = 0; i < now; i++){

					printf("%4s\t%12s\t", hakbun[i], name[i]);

					for (int j = 0; j < 5; j++)
						printf("%3d\t", score[i][j]);

					printf("%5.2f\t%3d\n", aver[i], rank[i]);
				}
				cout << "����������������������������������������������������������������������������" << endl;

				cout << "�� ����\t\t   ";
				for (int i = 0; i < 5; i++)
					printf("%8d", score[pre][i]);

				cout << "\n�� ���\t\t   ";
				for (int i = 0; i < 4; i++)
					printf("%8.2f", sum_aver[i]);
				printf("\t%13.2f", sum_aver[4]);

				cout << endl << endl << "****************************************************************************" << endl;
			}

			cout << "�ƹ�Ű�� ������ �޴��� ���ư��ϴ�.";
			_getch();

			break;


		case 3:

			cout << "�����մϴ�.\n\n";

			for (int i = 0; i < pre; i++){
				delete[] hakbun[i];
				delete[] name[i];
			}

			for (int i = 0; i < pre + 1; i++){
				delete[] score[i];
			}

			delete[] hakbun;
			delete[] name;
			delete[] score;
			delete[] aver;
			delete[] rank;

			return 0;

		}
		system("cls");
	}
	return 0;
}