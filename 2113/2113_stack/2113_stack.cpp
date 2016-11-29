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
	system("title 착착 쌓아라");
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
	bool exact = false; //정확히 맞추면 점수가 2배

loop: //goto문이 그닥 좋지 않은 것은 알고 있지만 일일히 flag로 다중 루프를 빠져나가는 것보다 1개쯤 쓰는 것이 더 깔끔하다고 생각합니다 :)

	system("cls");
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	cout << "■                                            선택후 엔터를 누르세요■";
	cout << "■                                                                  ■";
	cout << "■                 ■                   ■                          ■";
	cout << "■         ■      ■           ■      ■                          ■";
	cout << "■         ■      ■           ■      ■                          ■";
	cout << "■         ■      ■           ■      ■             게임시작     ■";
	cout << "■     ■■■■■  ■■■   ■■■■■  ■■■                      ■";
	cout << "■         ■      ■           ■      ■                          ■";
	cout << "■       ■  ■    ■         ■  ■    ■             랭킹보기     ■";
	cout << "■       ■  ■    ■         ■  ■    ■                          ■";
	cout << "■       ■  ■    ■         ■  ■    ■                          ■";
	cout << "■                 ■                   ■             하는방법     ■";
	cout << "■                                                                  ■";
	cout << "■          ■■■■             ■■■■                           ■";
	cout << "■                ■                   ■              종료하기     ■";
	cout << "■                ■                   ■                           ■";
	cout << "■                ■                   ■                           ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                               최고기록 :       점■";
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";

	loadHighScore(20);

	gotoxy(51, fingerY);
	cout << "☞";

	while (true){
		c = _getch();
		if (c == UP){
			if (wherey() != 6){
				gotoxy(51, fingerY);
				cout << "  ";
				fingerY -= 3;
				gotoxy(51, fingerY);
				cout << "☞";
			}
		}
		else if (c == DOWN){
			if (wherey() != 15){
				gotoxy(51, fingerY);
				cout << "  ";
				fingerY += 3;
				gotoxy(51, fingerY);
				cout << "☞";
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
			if (x == 70 - barCnt - 2) //전체에서 바 크기 빼고 테두리 빼고
				rL = LEFT;
			Sleep(speed);
		}
		else{
			gotoxy(x + barCnt - 1, y); //자리 비워주기
			cout << " ";
			x--;
			gotoxy(x, y);
			for (i = 1; i <= barCnt; i++)
				cout << '=';
			if (x == 2)
				rL = RIGHT;
			Sleep(speed);
		} //바가 양 옆에 부딪히면 다시 반대쪽으로		

		if (_kbhit()){ //키보드가 눌렸는지 확인
			c = _getch();
			if (c == ESC) //언제나 ESC가 눌리면 종료
				exit(0);
			else if (c == ' '){ //스페이스가 눌리면 비교

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
					barCnt -= wherex() - cursorEnd; //자르기
					exact = false;
				}

				Sleep(50); //시각적으로 정확하게 보이기 위해서!!

				gotoxy(x, y + 1); //한줄 아래에 출력하기 위해

				for (i = 1; i <= barCnt; i++)
					cout << '=';
				cursorEnd = wherex();

				if (barCnt <= 0){ //바 사이즈가 0이하면 게임 오버
					for (i = 1; i <= 2; i++){
						Sleep(200);
						gotoxy(25, 2);
						cout << "★☆ GAME OVER ☆★";
						Sleep(200);
						gotoxy(25, 2);
						cout << "                   ";
					} //반짝거리는 효과

					Sleep(200);
					gotoxy(25, 2);
					cout << "★☆ GAME OVER ☆★";

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
					exact = false; //전부 초기화 : goto문을 선언 전에 주면 문제가 일어날까봐요ㅠ.ㅠ

					goto loop;
					//게임오버 함수에서 돌아왔다는 것은 메인으로를 누른 것이기 때문에 loop로 이동한다
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
				x = 3; //다시 왼쪽부터 나온다
				rL = RIGHT;

				if (y == 2){
					Sleep(500);
					printOutside();

					for (i = 1; i <= 3; i++){
						Sleep(200);
						gotoxy(23, 10);
						cout << "★☆ " << round << " 라운드 통과 ☆★";
						Sleep(200);
						gotoxy(23, 10);
						cout << "                           ";
					} //반짝거리는 효과

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
							cout << "★☆ 최종 라운드를 통과하셨습니다 ☆★";
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
							exact = false; //전부 초기화 : goto문을 선언 전에 주면 문제가 일어날까봐요ㅠ.ㅠ

							goto loop;
							//파이널 함수에서 돌아왔다는 것은 메인으로를 누른 것이기 때문에 loop로 이동한다
						}
					}

					gotoxy(15, 10);
					cout << round << " 라운드를 시작하려면 엔터를 눌러주세요";
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
					cursorEnd = wherex(); //다시 첫번째 바 출력
					printScore(round, score);
				} //새로운 라운드

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
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	cout << "■                                                 종료하기 : ESC 키■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
}

void showHowTo(){
	//하는 방법을 보여줌
	system("cls");
	printOutside();
	gotoxy(4, 2);
	cout << "안녕하세요!";
	gotoxy(4, 3);
	cout << "저는 착착 쌓아라의 방법을 설명해주는 채윤npc예요. ~^-^~";
	gotoxy(4, 4);
	cout << "일단 착착 쌓아라는요, 스페이스바를 눌러서 움직이는 바를 멈추는";
	gotoxy(4, 5);
	cout << "것이 기본 동작이에요. 하지만 마음대로 하면 게임이 아니겠죠?";
	gotoxy(4, 6);
	cout << "밑에 이미 놓여져 있는 바의 크기에 맞춰서 멈추지 않으면 넘어간";
	gotoxy(4, 7);
	cout << "부분은 잘려버려요 ㅠ.ㅠ";
	gotoxy(4, 8);
	cout << "한 라운드는 총 16개의 바를 멈추게 되는데 그 전에 남아있는";
	gotoxy(4, 9);
	cout << "크기가 없게 된다면 게임 오버랍니다!";
	gotoxy(4, 10);
	cout << "5라운드까지는 속도가 빨라지고, 그 이후부터는 기본으로 주어지는";
	gotoxy(4, 11);
	cout << "바의 크기가 작아져요. 그리고 게임이 끝나면 점수를 저장할 수";
	gotoxy(4, 12);
	cout << "있어요~ 최고 점수 1개와 최근 점수 7개가 저장이 된답니다!";
	gotoxy(4, 14);
	cout << "메인메뉴로 돌아가려면 아무키나 눌러주세요. 그럼, GOOD LUCK!";

	c = _getch();
	if (c == ESC){
		gotoxy(30, 20);
		exit(0);
	}
}

void printScore(int round, int score){
	gotoxy(2, 1);
	cout << round << " 라운드 : " << score << " 점"; //라운드와 점수 출력
}

void showGameOver(int score){
	int fingerY = 5;

	system("cls");
	saveScore(score);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	cout << "■                                                                  ■";
	cout << "■                     당신의 점수 : ";
	printf("%6d 점                      ■", score);
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■                              메인으로                            ■";
	cout << "■                                                                  ■";
	cout << "■                              종료하기                            ■";
	cout << "■                                                                  ■";
	cout << "■        ■■■■                                                  ■";
	cout << "■        ■■■■                                                  ■";
	cout << "■        ■■■■■■■■■■■■■■■■■■■                    ■";
	cout << "■        ■■■■      ■                    ■                    ■";
	cout << "■                      ■                    ■                    ■";
	cout << "■                      ■                    ■                    ■";
	cout << "■                      ■                    ■                    ■";
	cout << "■                      ■                    ■                    ■";
	cout << "■                      ■                    ■                    ■";
	cout << "■                      ■                    ■■■■■■■        ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";

	gotoxy(28, fingerY);
	cout << "☞";

	while (true){
		c = _getch();
		if (c == UP){
			if (wherey() != 5){
				gotoxy(28, fingerY);
				cout << "  ";
				fingerY -= 2;
				gotoxy(28, fingerY);
				cout << "☞";
			}
		}
		else if (c == DOWN){
			if (wherey() != 7){
				gotoxy(28, fingerY);
				cout << "  ";
				fingerY += 2;
				gotoxy(28, fingerY);
				cout << "☞";
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
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	cout << "■                                                                  ■";
	cout << "■                     당신의 점수 : ";
	printf("%6d 점                      ■", score);
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■             ■               메인으로             ■             ■";
	cout << "■           ■■■                                ■■■           ■";
	cout << "■         ■■■■■           종료하기         ■■■■■         ■";
	cout << "■           ■■■                                ■■■           ■";
	cout << "■             ■                                    ■             ■";
	cout << "■                      ■                   ■                     ■";
	cout << "■                    ■■■                 ■                     ■";
	cout << "■        ■            ■            ■     ■           ■        ■";
	cout << "■      ■■■        ■  ■        ■■■   ■         ■■■      ■";
	cout << "■    ■■■■■                             ■■■   ■■■■■    ■";
	cout << "■      ■■■      ■■■■■        ■     ■         ■■■      ■";
	cout << "■        ■            ■                   ■           ■        ■";
	cout << "■                    ■■■                 ■                     ■";
	cout << "■                        ■                 ■                     ■";
	cout << "■                                                                  ■";
	cout << "■                                                                  ■";
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";

	gotoxy(28, fingerY);
	cout << "☞";

	while (true){
		c = _getch();
		if (c == UP){
			if (wherey() != 4){
				gotoxy(28, fingerY);
				cout << "  ";
				fingerY -= 2;
				gotoxy(28, fingerY);
				cout << "☞";
			}
		}
		else if (c == DOWN){
			if (wherey() != 8){
				gotoxy(28, fingerY);
				cout << "  ";
				fingerY += 2;
				gotoxy(28, fingerY);
				cout << "☞";
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
	//최근 점수를 보여줌
	ifstream ifs("score.txt");
	char line[255];
	char* token = NULL;
	short y = 3;
	short count = 1;

	printOutside();
	gotoxy(49, 2);
	cout << "최고기록 :       점";
	loadHighScore(2);

	if (!ifs){
		gotoxy(22, 8);
		cout << "게임을 한 번도 안하셨나요?";
		gotoxy(15, 10);
		cout << "이곳은 게임의 결과를 보여주는 곳 입니다";
		gotoxy(22, 12);
		cout << "게임을 하고 들어와 주세요";
		gotoxy(20, 19);
		cout << "돌아가려면 아무 키나 누르세요";

		c = _getch();
		if (c == ESC){
			gotoxy(30, 20);
			exit(0);
		}
		return;
	}

	gotoxy(19, y);
	cout << "<< 착착 쌓아라 최근 7개의 점수 >>";

	while (ifs.getline(line, 255) && count <= 7)
	{
		y += 2;

		token = strtok(line, "\t"); //자바에서 배운 토크나이저 비슷
		gotoxy(25, y);
		cout << token;

		token = strtok(NULL, " ");
		gotoxy(37, y);
		printf("%6s 점", token);

		count++;
	}

	gotoxy(20, 19);
	cout << "돌아가려면 아무 키나 누르세요";

	c = _getch();
	if (c == ESC){
		gotoxy(30, 20);
		exit(0);
	}
}

void saveScore(int score){
	//score.txt 파일에 이니셜과 점수를 저장함
	ofstream ofs("score.txt", ios::out | ios::app);
	char* initial = new char;

	printOutside();

	if (!ofs){
		gotoxy(20, 10);
		cout << "죄송합니다 오류가 발생했습니다";
		Sleep(1000);
		return;
	}

	gotoxy(22, 10);
	cout << "이니셜을 입력하세요 : ";
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
	} //최대점수 읽어오기
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