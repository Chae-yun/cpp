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
	short fingerY = 7;
	bool rL = RIGHT;
	bool exact = false; //정확히 맞추면 점수가 2배

loop: //goto문이 그닥 좋지 않은 것은 알고 있지만 일일히 flag로 다중 루프를 빠져나가는 것보다 1개쯤 쓰는 것이 더 깔끔하다고 생각합니다 :)

	system("cls");
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
	cout << "■                                            선택후 엔터를 누르세요■";
	cout << "■                                         종료하려면 ESC를 누르세요■";
	cout << "■                                                                  ■";
	cout << "■                 ■                   ■                          ■";
	cout << "■         ■      ■           ■      ■                          ■";
	cout << "■         ■      ■           ■      ■                          ■";
	cout << "■         ■      ■           ■      ■             게임시작     ■";
	cout << "■     ■■■■■  ■■■   ■■■■■  ■■■                      ■";
	cout << "■         ■      ■           ■      ■                          ■";
	cout << "■       ■  ■    ■         ■  ■    ■             최근점수     ■";
	cout << "■     ■      ■  ■       ■      ■  ■                          ■";
	cout << "■     ■      ■  ■       ■      ■  ■                          ■";
	cout << "■                 ■                   ■             랭킹보기     ■";
	cout << "■                                                                  ■";
	cout << "■          ■■■■             ■■■■                           ■";
	cout << "■                ■                   ■              하는방법     ■";
	cout << "■                ■                   ■                           ■";
	cout << "■                ■                   ■                           ■";
	cout << "■                                                                  ■";
	cout << "■                                               최고기록 :       점■";
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";

	loadHighScore(20);
	loadLastRank();

	gotoxy(51, fingerY);
	cout << "☞";

	while (true){
		c = _getch();
		if (c == UP){
			if (wherey() != 7){
				gotoxy(51, fingerY);
				cout << "  ";
				fingerY -= 3;
				gotoxy(51, fingerY);
				cout << "☞";
			}
		}
		else if (c == DOWN){
			if (wherey() != 16){
				gotoxy(51, fingerY);
				cout << "  ";
				fingerY += 3;
				gotoxy(51, fingerY);
				cout << "☞";
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
	cout << "＠＠ SPACE BAR ＠＠";

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
			if (c == ESC){ //언제나 ESC가 눌리면 종료
				gotoxy(30, 1);
				exit(0);
			}
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
						gotoxy(26, 12);
						cout << "★☆ 속도 UP ☆★";
					}
					else{
						gotoxy(24, 12);
						cout << "★☆ 바 크기 DOWN ☆★";
						highBarCnt -= 3;
						barCnt = highBarCnt;
						if (barCnt <= 0){
							gotoxy(16, 10);
							cout << "★☆ 최종 라운드를 통과하셨습니다 ☆★";
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
					gotoxy(25, 2);
					cout << "＠＠ SPACE BAR ＠＠";
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
	cout << "있어요~ 최고 점수 1개와 최근 점수 7개, 높은 점수 7개가 저장이";
	gotoxy(4, 13);
	cout << "된답니다! 랭킹에 들어갈 수 있도록 열심히 해보세요 @-@";
	gotoxy(4, 14);
	cout << "같은 점수는 동일 순위로 처리가 되지만 만약 7개의 점수가 가득";
	gotoxy(4, 15);
	cout << "차 있는 상태에서 마지막 순위와 점수가 같다면 그 전 사람이 밀려";
	gotoxy(4, 16);
	cout << "나게 된답니다. 일종의 마케팅이랄까요 ㅇㅅㅇ?";
	gotoxy(4, 18);
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

void showLastScore(){
	//최근 점수를 보여줌
	ifstream ifs("lastScore.txt");
	char line[255];
	char* token = NULL;
	short y = 3;

	printOutside();

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

		ifs.close();

		return;
	}

	gotoxy(19, y);
	cout << "<< 착착 쌓아라 최근 7개의 점수 >>";

	while (ifs.getline(line, 255))
	{
		y += 2;

		token = strtok(line, "\t"); //자바에서 배운 토크나이저 비슷
		gotoxy(25, y);
		cout << token;

		token = strtok(NULL, " ");
		gotoxy(37, y);
		printf("%6s 점", token);
	}

	gotoxy(20, 19);
	cout << "돌아가려면 아무 키나 누르세요";

	c = _getch();
	if (c == ESC){
		gotoxy(30, 20);
		exit(0);
	}
}

void showRank(){
	//랭킹를 보여줌
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

		ifs.close();

		return;
	}

	gotoxy(19, y);
	cout << "<< 착착 쌓아라 최고 7개의 점수 >>";

	while (ifs.getline(line, 255))
	{
		y += 2;

		token = strtok(line, "\t"); //자바에서 배운 토크나이저 비슷
		gotoxy(28, y);
		cout << token;

		token = strtok(NULL, " ");
		gotoxy(40, y);
		printf("%6s 점", token);

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
	cout << "돌아가려면 아무 키나 누르세요";

	c = _getch();
	if (c == ESC){
		gotoxy(30, 20);
		exit(0);
	}
}

void saveScore(int score){
	//lastScore.txt 파일과 lank.txt에 이니셜과 점수를 저장함
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
		cout << "랭킹에 이름을 남길 수 있게 되었습니다";
		gotoxy(18, 8);
		cout << "최근 점수에도 물론 기록이 남습니다";
	}
	else{
		gotoxy(18, 6);
		cout << "랭킹에 이름을 남기기에 부족합니다";
		gotoxy(17, 7);
		cout << "그러나 최근 점수에는 기록이 남습니다";
	}

	gotoxy(21, 10);
	cout << "※ 공백만 입력하지 마세요 ※";
	gotoxy(13, 11);
	cout << "※ 10글자(한글은 5글자)를 넘기면 잘립니다 ※";
	gotoxy(25, 13);
	cout << "이니셜을 입력하세요";
	gotoxy(28, 14);
	cout << "=> ";

	gets(Ninitial);

	while (strlen(Ninitial) == 0){ //바로 엔터를 눌렀을 경우 체크
		for (i = 1; i <= 2; i++){
			gotoxy(31, 14);
			cout << "입력하세요!";
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
	} //헤헤 유효성 검사 해서 런타임 에러가 나지 않아요!!!!!!!ㅠㅠㅠㅠ

	ifs.open("lastScore.txt");

	if (!ifs){
		strcpy(initArr[0], initial);
		scoreArr[0] = score;
	}
	else{
		i = 0;

		while (ifs.getline(line, 255))
		{
			token = strtok(line, "\t"); //자바에서 배운 토크나이저 비슷
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
			scoreArr[i + 1] = scoreArr[i]; //한칸씩 밑으로 덮어쓰고
		}

		strcpy(initArr[0], initial);
		scoreArr[0] = score; //맨 위에 방금 점수를 덮어쓴다
	}

	ofs.open("lastScore.txt");

	if (!ofs){
		gotoxy(20, 10);
		cout << "죄송합니다 오류가 발생했습니다";
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

	if (score >= lastRankScore){ //랭킹에 들어갈 수 있을 때만 실행

		ifs.open("rank.txt");

		if (!ifs){
			strcpy(initArr[0], initial);
			scoreArr[0] = score;
		}
		else{
			i = 0;

			while (ifs.getline(line, 255))
			{
				token = strtok(line, "\t"); //자바에서 배운 토크나이저 비슷
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
				//자리 있으니까 다음 칸에 넣음
			}
			else{
				strcpy(initArr[i - 1], initial);
				scoreArr[i - 1] = score;
				//자리없는데 여기 들어온 것은 가장 낮은 랭킹 점수보다 같거나 높은 거니까 거기에 덮어씀
			}

			bool flag = true;
			int j = 0;

			while (flag == true){ //그리고 정렬
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
			cout << "죄송합니다 오류가 발생했습니다";
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
			token = strtok(line, "\t"); //자바에서 배운 토크나이저 비슷
			lastRankinit = token;
			token = strtok(NULL, " ");
			lastRankScore = atoi(token);

			if (i != 7)
				lastRankScore = 0; //가득 차있을 때만 의마가 있도록
		}
	}

	ifs.close();
}