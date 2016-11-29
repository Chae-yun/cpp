#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define RIGHT 0
#define LEFT 1
#define ESC 27
#define ENTER 13
#define UP 72
#define DOWN 80
using namespace std;

void gotoxy(int x, int y);
int wherex();
int wherey();
void printOutside();
void showHowTo();
void printScore(int round, int score);
void showGameOver(int score);
void showFinal(int score);
void showLastScore();
void showRank();
void saveScore(int score);
void loadHighScore(short y);
void saveHighScore(int score);
void loadLastRank();

char c;
short highScore;
short lastRankScore;
char* lastRankinit;

int main(){
	system("mode con:cols=71 lines=22");
	system("title ���� �׾ƶ�");
	system("color 4F");

	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	cursor.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

	int i;
	short score = 0;
	short round = 1;
	short increase = 10;
	short x = 3;
	short y = 18;
	short barCnt = 24;
	short highBarCnt = 24;
	short cursorEnd;
	short speed = 20;
	short fingerY = 7;
	bool rL = RIGHT;
	bool exact = false; //��Ȯ�� ���߸� ������ 2��

loop: //goto���� �״� ���� ���� ���� �˰� ������ ������ flag�� ���� ������ ���������� �ͺ��� 1���� ���� ���� �� ����ϴٰ� �����մϴ� :)

	system("cls");
	cout << "������������������������������������";
	cout << "��                                            ������ ���͸� ���������";
	cout << "��                                         �����Ϸ��� ESC�� ���������";
	cout << "��                                                                  ��";
	cout << "��                 ��                   ��                          ��";
	cout << "��         ��      ��           ��      ��                          ��";
	cout << "��         ��      ��           ��      ��                          ��";
	cout << "��         ��      ��           ��      ��             ���ӽ���     ��";
	cout << "��     ������  ����   ������  ����                      ��";
	cout << "��         ��      ��           ��      ��                          ��";
	cout << "��       ��  ��    ��         ��  ��    ��             �ֱ�����     ��";
	cout << "��     ��      ��  ��       ��      ��  ��                          ��";
	cout << "��     ��      ��  ��       ��      ��  ��                          ��";
	cout << "��                 ��                   ��             ��ŷ����     ��";
	cout << "��                                                                  ��";
	cout << "��          �����             �����                           ��";
	cout << "��                ��                   ��              �ϴ¹��     ��";
	cout << "��                ��                   ��                           ��";
	cout << "��                ��                   ��                           ��";
	cout << "��                                                                  ��";
	cout << "��                                               �ְ��� :       ����";
	cout << "������������������������������������";

	loadHighScore(20);
	loadLastRank();

	gotoxy(51, fingerY);
	cout << "��";

	while (true){
		c = _getch();
		if (c == UP){
			if (wherey() != 7){
				gotoxy(51, fingerY);
				cout << "  ";
				fingerY -= 3;
				gotoxy(51, fingerY);
				cout << "��";
			}
		}
		else if (c == DOWN){
			if (wherey() != 16){
				gotoxy(51, fingerY);
				cout << "  ";
				fingerY += 3;
				gotoxy(51, fingerY);
				cout << "��";
			}
		}
		else if (c == ENTER){
			if (wherey() == 7)
				break;
			else if (wherey() == 10){
				showLastScore();
				goto loop;
			}
			else if (wherey() == 13){
				showRank();
				goto loop;
			}
			else if (wherey() == 16){
				showHowTo();
				goto loop;
			}
		}
		else if (c == ESC){
			gotoxy(30, 20);
			exit(0);
		}
	}
	printOutside();
	gotoxy(23, 20);
	for (i = 1; i <= barCnt; i++)
		cout << '=';
	cursorEnd = wherex();

	printScore(round, score);
	gotoxy(25, 2);
	cout << "���� SPACE BAR ����";

	while (true)
	{
		if (rL == RIGHT){
			gotoxy(x, y);
			cout << " ";
			x++;
			for (i = 1; i <= barCnt; i++)
				cout << '=';
			if (x == 70 - barCnt - 2) //��ü���� �� ũ�� ���� �׵θ� ����
				rL = LEFT;
			Sleep(speed);
		}
		else{
			gotoxy(x + barCnt - 1, y); //�ڸ� ����ֱ�
			cout << " ";
			x--;
			gotoxy(x, y);
			for (i = 1; i <= barCnt; i++)
				cout << '=';
			if (x == 2)
				rL = RIGHT;
			Sleep(speed);
		} //�ٰ� �� ���� �ε����� �ٽ� �ݴ�������		

		if (_kbhit()){ //Ű���尡 ���ȴ��� Ȯ��
			c = _getch();
			if (c == ESC){ //������ ESC�� ������ ����
				gotoxy(30, 1);
				exit(0);
			}
			else if (c == ' '){ //�����̽��� ������ ��

				gotoxy(x, y);
				for (i = 1; i <= barCnt; i++)
					cout << ' ';

				if (wherex() < cursorEnd){
					x = cursorEnd - barCnt;
					barCnt = wherex() - x;
					exact = false;
				}
				else if (wherex() == cursorEnd)
					exact = true;
				else{
					barCnt -= wherex() - cursorEnd; //�ڸ���
					exact = false;
				}

				Sleep(50); //�ð������� ��Ȯ�ϰ� ���̱� ���ؼ�!!

				gotoxy(x, y + 1); //���� �Ʒ��� ����ϱ� ����

				for (i = 1; i <= barCnt; i++)
					cout << '=';
				cursorEnd = wherex();

				if (barCnt <= 0){ //�� ����� 0���ϸ� ���� ����
					for (i = 1; i <= 2; i++){
						Sleep(200);
						gotoxy(25, 2);
						cout << "�ڡ� GAME OVER �١�";
						Sleep(200);
						gotoxy(25, 2);
						cout << "                   ";
					} //��¦�Ÿ��� ȿ��

					Sleep(200);
					gotoxy(25, 2);
					cout << "�ڡ� GAME OVER �١�";

					Sleep(1000);
					showGameOver(score);
					saveHighScore(score);

					score = 0;
					round = 1;
					increase = 10;
					x = 3;
					y = 18;
					barCnt = 24;
					highBarCnt = 24;
					speed = 20;
					rL = RIGHT;
					exact = false; //���� �ʱ�ȭ : goto���� ���� ���� �ָ� ������ �Ͼ������.��

					goto loop;
					//���ӿ��� �Լ����� ���ƿԴٴ� ���� �������θ� ���� ���̱� ������ loop�� �̵��Ѵ�
				}
				else{
					if (exact)
						score += 2 * increase;
					else
						score += increase;
					printScore(round, score);
				}

				y--;

				Sleep(200);
				x = 3; //�ٽ� ���ʺ��� ���´�
				rL = RIGHT;

				if (y == 2){
					Sleep(500);
					printOutside();

					for (i = 1; i <= 3; i++){
						Sleep(200);
						gotoxy(23, 10);
						cout << "�ڡ� " << round << " ���� ��� �١�";
						Sleep(200);
						gotoxy(23, 10);
						cout << "                           ";
					} //��¦�Ÿ��� ȿ��

					x = 3;
					y = 18;
					increase += round * 2;
					round++;
					rL = RIGHT;

					if (round <= 5){
						barCnt = 24;
						speed -= 2;
						gotoxy(26, 12);
						cout << "�ڡ� �ӵ� UP �١�";
					}
					else{
						gotoxy(24, 12);
						cout << "�ڡ� �� ũ�� DOWN �١�";
						highBarCnt -= 3;
						barCnt = highBarCnt;
						if (barCnt <= 0){
							gotoxy(16, 10);
							cout << "�ڡ� ���� ���带 ����ϼ̽��ϴ� �١�";
							Sleep(1000);
							showFinal(score);
							saveHighScore(score);

							score = 0;
							round = 1;
							increase = 10;
							x = 3;
							y = 18;
							barCnt = 24;
							highBarCnt = 24;
							speed = 20;
							rL = RIGHT;
							exact = false; //���� �ʱ�ȭ : goto���� ���� ���� �ָ� ������ �Ͼ������.��

							goto loop;
							//���̳� �Լ����� ���ƿԴٴ� ���� �������θ� ���� ���̱� ������ loop�� �̵��Ѵ�
						}
					}

					gotoxy(15, 10);
					cout << round << " ���带 �����Ϸ��� ���͸� �����ּ���";
					while (true){
						c = _getch();
						if (c == ENTER)
							break;
						else if (c == ESC)
							return 0;
					}
					printOutside();
					gotoxy((70 - barCnt) / 2, 20);
					for (i = 1; i <= barCnt; i++)
						cout << '=';
					cursorEnd = wherex(); //�ٽ� ù��° �� ���
					printScore(round, score);
					gotoxy(25, 2);
					cout << "���� SPACE BAR ����";
				} //���ο� ����

				continue;
			}
		}
	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

void printOutside(){
	system("cls");
	cout << "������������������������������������";
	cout << "��                                                 �����ϱ� : ESC Ű��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "������������������������������������";
}

void showHowTo(){
	//�ϴ� ����� ������
	system("cls");
	printOutside();
	gotoxy(4, 2);
	cout << "�ȳ��ϼ���!";
	gotoxy(4, 3);
	cout << "���� ���� �׾ƶ��� ����� �������ִ� ä��npc����. ~^-^~";
	gotoxy(4, 4);
	cout << "�ϴ� ���� �׾ƶ�¿�, �����̽��ٸ� ������ �����̴� �ٸ� ���ߴ�";
	gotoxy(4, 5);
	cout << "���� �⺻ �����̿���. ������ ������� �ϸ� ������ �ƴϰ���?";
	gotoxy(4, 6);
	cout << "�ؿ� �̹� ������ �ִ� ���� ũ�⿡ ���缭 ������ ������ �Ѿ";
	gotoxy(4, 7);
	cout << "�κ��� �߷������� ��.��";
	gotoxy(4, 8);
	cout << "�� ����� �� 16���� �ٸ� ���߰� �Ǵµ� �� ���� �����ִ�";
	gotoxy(4, 9);
	cout << "ũ�Ⱑ ���� �ȴٸ� ���� �������ϴ�!";
	gotoxy(4, 10);
	cout << "5��������� �ӵ��� ��������, �� ���ĺ��ʹ� �⺻���� �־�����";
	gotoxy(4, 11);
	cout << "���� ũ�Ⱑ �۾�����. �׸��� ������ ������ ������ ������ ��";
	gotoxy(4, 12);
	cout << "�־��~ �ְ� ���� 1���� �ֱ� ���� 7��, ���� ���� 7���� ������";
	gotoxy(4, 13);
	cout << "�ȴ�ϴ�! ��ŷ�� �� �� �ֵ��� ������ �غ����� @-@";
	gotoxy(4, 14);
	cout << "���� ������ ���� ������ ó���� ������ ���� 7���� ������ ����";
	gotoxy(4, 15);
	cout << "�� �ִ� ���¿��� ������ ������ ������ ���ٸ� �� �� ����� �з�";
	gotoxy(4, 16);
	cout << "���� �ȴ�ϴ�. ������ �������̶���� ������?";
	gotoxy(4, 18);
	cout << "���θ޴��� ���ư����� �ƹ�Ű�� �����ּ���. �׷�, GOOD LUCK!";

	c = _getch();
	if (c == ESC){
		gotoxy(30, 20);
		exit(0);
	}
}

void printScore(int round, int score){
	gotoxy(2, 1);
	cout << round << " ���� : " << score << " ��"; //����� ���� ���
}

void showGameOver(int score){
	int fingerY = 5;

	system("cls");
	saveScore(score);

	cout << "������������������������������������";
	cout << "��                                                                  ��";
	cout << "��                     ����� ���� : ";
	printf("%6d ��                      ��", score);
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                              ��������                            ��";
	cout << "��                                                                  ��";
	cout << "��                              �����ϱ�                            ��";
	cout << "��                                                                  ��";
	cout << "��        �����                                                  ��";
	cout << "��        �����                                                  ��";
	cout << "��        ��������������������                    ��";
	cout << "��        �����      ��                    ��                    ��";
	cout << "��                      ��                    ��                    ��";
	cout << "��                      ��                    ��                    ��";
	cout << "��                      ��                    ��                    ��";
	cout << "��                      ��                    ��                    ��";
	cout << "��                      ��                    ��                    ��";
	cout << "��                      ��                    ��������        ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "������������������������������������";

	gotoxy(28, fingerY);
	cout << "��";

	while (true){
		c = _getch();
		if (c == UP){
			if (wherey() != 5){
				gotoxy(28, fingerY);
				cout << "  ";
				fingerY -= 2;
				gotoxy(28, fingerY);
				cout << "��";
			}
		}
		else if (c == DOWN){
			if (wherey() != 7){
				gotoxy(28, fingerY);
				cout << "  ";
				fingerY += 2;
				gotoxy(28, fingerY);
				cout << "��";
			}
		}
		else if (c == ENTER){
			if (wherey() == 5)
				return;
			else if (wherey() == 7){
				gotoxy(30, 20);
				exit(0);
			}
		}
	}
}

void showFinal(int score){
	int fingerY = 5;

	system("cls");
	saveScore(score);

	cout << "������������������������������������";
	cout << "��                                                                  ��";
	cout << "��                     ����� ���� : ";
	printf("%6d ��                      ��", score);
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��             ��               ��������             ��             ��";
	cout << "��           ����                                ����           ��";
	cout << "��         ������           �����ϱ�         ������         ��";
	cout << "��           ����                                ����           ��";
	cout << "��             ��                                    ��             ��";
	cout << "��                      ��                   ��                     ��";
	cout << "��                    ����                 ��                     ��";
	cout << "��        ��            ��            ��     ��           ��        ��";
	cout << "��      ����        ��  ��        ����   ��         ����      ��";
	cout << "��    ������                             ����   ������    ��";
	cout << "��      ����      ������        ��     ��         ����      ��";
	cout << "��        ��            ��                   ��           ��        ��";
	cout << "��                    ����                 ��                     ��";
	cout << "��                        ��                 ��                     ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "������������������������������������";

	gotoxy(28, fingerY);
	cout << "��";

	while (true){
		c = _getch();
		if (c == UP){
			if (wherey() != 4){
				gotoxy(28, fingerY);
				cout << "  ";
				fingerY -= 2;
				gotoxy(28, fingerY);
				cout << "��";
			}
		}
		else if (c == DOWN){
			if (wherey() != 8){
				gotoxy(28, fingerY);
				cout << "  ";
				fingerY += 2;
				gotoxy(28, fingerY);
				cout << "��";
			}
		}
		else if (c == ENTER){
			if (wherey() == 5)
				return;
			else if (wherey() == 7){
				gotoxy(30, 20);
				exit(0);
			}
		}
	}
}

void showLastScore(){
	//�ֱ� ������ ������
	ifstream ifs("lastScore.txt");
	char line[255];
	char* token = NULL;
	short y = 3;

	printOutside();

	if (!ifs){
		gotoxy(22, 8);
		cout << "������ �� ���� ���ϼ̳���?";
		gotoxy(15, 10);
		cout << "�̰��� ������ ����� �����ִ� �� �Դϴ�";
		gotoxy(22, 12);
		cout << "������ �ϰ� ���� �ּ���";
		gotoxy(20, 19);
		cout << "���ư����� �ƹ� Ű�� ��������";

		c = _getch();
		if (c == ESC){
			gotoxy(30, 20);
			exit(0);
		}

		ifs.close();

		return;
	}

	gotoxy(19, y);
	cout << "<< ���� �׾ƶ� �ֱ� 7���� ���� >>";

	while (ifs.getline(line, 255))
	{
		y += 2;

		token = strtok(line, "\t"); //�ڹٿ��� ��� ��ũ������ ���
		gotoxy(25, y);
		cout << token;

		token = strtok(NULL, " ");
		gotoxy(37, y);
		printf("%6s ��", token);
	}

	gotoxy(20, 19);
	cout << "���ư����� �ƹ� Ű�� ��������";

	c = _getch();
	if (c == ESC){
		gotoxy(30, 20);
		exit(0);
	}
}

void showRank(){
	//��ŷ�� ������
	ifstream ifs("rank.txt");
	char line[255];
	char* token = NULL;
	short y = 3;
	short rank = 1;
	short beforeScore = 0;
	short equalRank = 1;

	printOutside();

	if (!ifs){
		gotoxy(22, 8);
		cout << "������ �� ���� ���ϼ̳���?";
		gotoxy(15, 10);
		cout << "�̰��� ������ ����� �����ִ� �� �Դϴ�";
		gotoxy(22, 12);
		cout << "������ �ϰ� ���� �ּ���";
		gotoxy(20, 19);
		cout << "���ư����� �ƹ� Ű�� ��������";

		c = _getch();
		if (c == ESC){
			gotoxy(30, 20);
			exit(0);
		}

		ifs.close();

		return;
	}

	gotoxy(19, y);
	cout << "<< ���� �׾ƶ� �ְ� 7���� ���� >>";

	while (ifs.getline(line, 255))
	{
		y += 2;

		token = strtok(line, "\t"); //�ڹٿ��� ��� ��ũ������ ���
		gotoxy(28, y);
		cout << token;

		token = strtok(NULL, " ");
		gotoxy(40, y);
		printf("%6s ��", token);

		gotoxy(23, y);

		if (beforeScore != atoi(token)){
			cout << rank;
			beforeScore = atoi(token);
			equalRank = rank;
		}
		else{
			cout << equalRank;
		}
		rank++;
	}

	gotoxy(20, 19);
	cout << "���ư����� �ƹ� Ű�� ��������";

	c = _getch();
	if (c == ESC){
		gotoxy(30, 20);
		exit(0);
	}
}

void saveScore(int score){
	//lastScore.txt ���ϰ� lank.txt�� �̴ϼȰ� ������ ������
	ofstream ofs;
	ifstream ifs;
	char Ninitial[50];
	char initial[11];
	char initArr[7][11];
	int scoreArr[7];
	char line[255];
	char* token = NULL;
	int i = 0;
	short count = 1;

	printOutside();

	if (score >= lastRankScore){
		gotoxy(17, 7);
		cout << "��ŷ�� �̸��� ���� �� �ְ� �Ǿ����ϴ�";
		gotoxy(18, 8);
		cout << "�ֱ� �������� ���� ����� �����ϴ�";
	}
	else{
		gotoxy(18, 6);
		cout << "��ŷ�� �̸��� ����⿡ �����մϴ�";
		gotoxy(17, 7);
		cout << "�׷��� �ֱ� �������� ����� �����ϴ�";
	}

	gotoxy(21, 10);
	cout << "�� ���鸸 �Է����� ������ ��";
	gotoxy(13, 11);
	cout << "�� 10����(�ѱ��� 5����)�� �ѱ�� �߸��ϴ� ��";
	gotoxy(25, 13);
	cout << "�̴ϼ��� �Է��ϼ���";
	gotoxy(28, 14);
	cout << "=> ";

	gets(Ninitial);

	while (strlen(Ninitial) == 0){ //�ٷ� ���͸� ������ ��� üũ
		for (i = 1; i <= 2; i++){
			gotoxy(31, 14);
			cout << "�Է��ϼ���!";
			Sleep(200);
			gotoxy(31, 14);
			cout << "                ";
			Sleep(200);
		}

		gotoxy(31, 14);
		gets(Ninitial);
	}
	if (strlen(Ninitial) < 10){
		strncpy(initial, Ninitial, strlen(Ninitial));
		initial[strlen(Ninitial)] = '\0';
	}
	else{ 
		strncpy(initial, Ninitial, 10);
		initial[10] = '\0';
	} //���� ��ȿ�� �˻� �ؼ� ��Ÿ�� ������ ���� �ʾƿ�!!!!!!!�ФФФ�

	ifs.open("lastScore.txt");

	if (!ifs){
		strcpy(initArr[0], initial);
		scoreArr[0] = score;
	}
	else{
		i = 0;

		while (ifs.getline(line, 255))
		{
			token = strtok(line, "\t"); //�ڹٿ��� ��� ��ũ������ ���
			strcpy(initArr[i], token);

			token = strtok(NULL, " ");
			scoreArr[i] = atoi(token);

			i++;
			count++;
		}

		ifs.close();
		ifs.clear();

		while (i != 0){
			i--;

			if (i == 6)
				continue;

			strcpy(initArr[i + 1], initArr[i]);
			scoreArr[i + 1] = scoreArr[i]; //��ĭ�� ������ �����
		}

		strcpy(initArr[0], initial);
		scoreArr[0] = score; //�� ���� ��� ������ �����
	}

	ofs.open("lastScore.txt");

	if (!ofs){
		gotoxy(20, 10);
		cout << "�˼��մϴ� ������ �߻��߽��ϴ�";
		ofs.close();
		return;
	}

	i = 0;

	while (count != i){
		ofs << initArr[i] << "\t" << scoreArr[i] << "\n";
		i++;
		if (i == 7)
			break;
	}

	ofs.close();
	ofs.clear();

	int scoreTemp;
	char initTemp[11];

	count = 1;

	if (score >= lastRankScore){ //��ŷ�� �� �� ���� ���� ����

		ifs.open("rank.txt");

		if (!ifs){
			strcpy(initArr[0], initial);
			scoreArr[0] = score;
		}
		else{
			i = 0;

			while (ifs.getline(line, 255))
			{
				token = strtok(line, "\t"); //�ڹٿ��� ��� ��ũ������ ���
				strcpy(initArr[i], token);

				token = strtok(NULL, " ");
				scoreArr[i] = atoi(token);

				i++;
				count++;
			}

			ifs.close();

			if (i != 7){
				strcpy(initArr[i], initial);
				scoreArr[i] = score;
				i++;
				//�ڸ� �����ϱ� ���� ĭ�� ����
			}
			else{
				strcpy(initArr[i - 1], initial);
				scoreArr[i - 1] = score;
				//�ڸ����µ� ���� ���� ���� ���� ���� ��ŷ �������� ���ų� ���� �Ŵϱ� �ű⿡ ���
			}

			bool flag = true;
			int j = 0;

			while (flag == true){ //�׸��� ����
				flag = false;
				j++;
				for (int k = 0; k < i - j; k++){
					if (scoreArr[k] < scoreArr[k + 1]){
						flag = true;

						scoreTemp = scoreArr[k];
						scoreArr[k] = scoreArr[k + 1];
						scoreArr[k + 1] = scoreTemp;

						strcpy(initTemp, initArr[k]);
						strcpy(initArr[k], initArr[k + 1]);
						strcpy(initArr[k + 1], initTemp);
					}
				}
			}
		}

		ofs.open("rank.txt");

		if (!ofs){
			gotoxy(20, 10);
			cout << "�˼��մϴ� ������ �߻��߽��ϴ�";
			ofs.close();
			return;
		}

		i = 0;

		while (count != i){
			ofs << initArr[i] << "\t" << scoreArr[i] << "\n";
			if (i == 6)
				break;
			i++;
		}

		ofs.close();
	}
}

void loadHighScore(short y){
	char line[15];
	ifstream ifs("highScore.txt");

	if (!ifs)
		highScore = 0;
	else{
		ifs.getline(line, 15);
		highScore = atoi(line);
	} //�ִ����� �о����
	gotoxy(60, y);
	printf("%6d", highScore);
	ifs.close();
}

void saveHighScore(int score){
	if (score > highScore){
		highScore = score;
		ofstream ofs("highScore.txt");
		ofs << highScore;
		ofs.close();
	}
}

void loadLastRank(){
	ifstream ifs("rank.txt");
	char line[255];
	char* token = NULL;
	short i = 0;

	if (!ifs)
		lastRankScore = 0;
	else{
		while (ifs.getline(line, 255))
		{
			i++;
			token = strtok(line, "\t"); //�ڹٿ��� ��� ��ũ������ ���
			lastRankinit = token;
			token = strtok(NULL, " ");
			lastRankScore = atoi(token);

			if (i != 7)
				lastRankScore = 0; //���� ������ ���� �Ǹ��� �ֵ���
		}
	}

	ifs.close();
}