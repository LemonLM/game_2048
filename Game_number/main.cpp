#include <iostream>
using namespace std;
#include <ctime>
#include "Game.h"
Game game;


int main()
{
	char ch;
	game.random_num();
	game.random_place();
	while(1)
	{
		system("cls");
		game.show();
		cin >> ch;
		switch(ch)
		{
		case 'w':game.moveUp();break;
		case 's':game.moveDown();break;
		case 'a':game.moveLeft();break;
		case 'd':game.moveRight();break;
		case 'p':exit(0);break;
		default:cout << "输入错误，请重新输入！" << endl;break;
		}
	}
	system("pause");
	
	return 0;
}

