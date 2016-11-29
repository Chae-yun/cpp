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
void showScore();
void saveScore(int score);
void loadHighScore(short y);
void saveHighScore(int score);

char c;
int highScore;

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
	short fingerY = 6;
	bool rL = RIGHT;
	bool exact = false; //��Ȯ�� ���߸� ������ 2��

loop: //goto���� �״� ���� ���� ���� �˰� ������ ������ flag�� ���� ������ ���������� �ͺ��� 1���� ���� ���� �� ����ϴٰ� �����մϴ� :)

	system("cls");
	cout << "������������������������������������";
	cout << "��                                            ������ ���͸� ���������";
	cout << "��                                                                  ��";
	cout << "��                 ��                   ��                          ��";
	cout << "��         ��      ��           ��      ��                          ��";
	cout << "��         ��      ��           ��      ��                          ��";
	cout << "��         ��      ��           ��      ��             ���ӽ���     ��";
	cout << "��     ������  ����   ������  ����                      ��";
	cout << "��         ��      ��           ��      ��                          ��";
	cout << "��       ��  ��    ��         ��  ��    ��             ��ŷ����     ��";
	cout << "��       ��  ��    ��         ��  ��    ��                          ��";
	cout << "��       ��  ��    ��         ��  ��    ��                          ��";
	cout << "��                 ��                   ��             �ϴ¹��     ��";
	cout << "��                                                                  ��";
	cout << "��          �����             �����                           ��";
	cout << "��                ��                   ��              �����ϱ�     ��";
	cout << "��                ��                   ��                           ��";
	cout << "��                ��                   ��                           ��";
	cout << "��                                                                  ��";
	cout << "��                                                                  ��";
	cout << "��                                               �ְ��� :       ����";
	cout << "������������������������������������";

	loadHighScore(20);

	gotoxy(51, fingerY);
	cout << "��";

	while (true){
		c = _getch();
		if (c == UP){
			if (wherey() != 6){
				gotoxy(51, fingerY);
				cout << "  ";
				fingerY -= 3;
				gotoxy(51, fingerY);
				cout << "��";
			}
		}
		else if (c == DOWN){
			if (wherey() != 15){
				gotoxy(51, fingerY);
				cout << "  ";
				fingerY += 3;
				gotoxy(51, fingerY);
				cout << "��";
			}
		}
		else if (c == ENTER){
			if (wherey() == 6)
				break;
			else if (wherey() == 9){
				showScore();
				goto loop;
			}
			else if (wherey() == 12){
				showHowTo();
				goto loop;
			}
			else if (wherey() == 15){
				gotoxy(30, 20);
				exit(0);
			}
		}
	}
	printOutside();
	gotoxy(23, 20);
	for (i = 1; i <= barCnt; i++)
		cout << '=';
	cursorEnd = wherex();

	printScore(round, score);

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
			if (c == ESC) //������ ESC�� ������ ����
				exit(0);
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
					saveHighScore(score);
					showGameOver(score);

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
					}
					else{
						highBarCnt -= 3;
						barCnt = highBarCnt;
						if (barCnt <= 0){
							gotoxy(16, 10);
							cout << "�ڡ� ���� ���带 ����ϼ̽��ϴ� �١�";
							Sleep(1000);
							saveHighScore(score);
							showFinal(score);

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
	cout << "�־��~ �ְ� ���� 1���� �ֱ� ���� 7���� ������ �ȴ�ϴ�!";
	gotoxy(4, 14);
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

void showScore(){
	//�ֱ� ������ ������
	ifstream ifs("score.txt");
	char line[255];
	char* token = NULL;
	short y = 3;
	short count = 1;

	printOutside();
	gotoxy(49, 2);
	cout << "�ְ��� :       ��";
	loadHighScore(2);

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
		return;
	}

	gotoxy(19, y);
	cout << "<< ���� �׾ƶ� �ֱ� 7���� ���� >>";

	while (ifs.getline(line, 255) && count <= 7)
	{
		y += 2;

		token = strtok(line, "\t"); //�ڹٿ��� ��� ��ũ������ ���
		gotoxy(25, y);
		cout << token;

		token = strtok(NULL, " ");
		gotoxy(37, y);
		printf("%6s ��", token);

		count++;
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
	//score.txt ���Ͽ� �̴ϼȰ� ������ ������
	ofstream ofs("score.txt", ios::out | ios::app);
	char* initial = new char;

	printOutside();

	if (!ofs){
		gotoxy(20, 10);
		cout << "�˼��մϴ� ������ �߻��߽��ϴ�";
		Sleep(1000);
		return;
	}

	gotoxy(22, 10);
	cout << "�̴ϼ��� �Է��ϼ��� : ";
	cin >> initial;

	ofs << initial << "\t" << score << "\n";

	ofs.close();
	Sleep(1000);
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