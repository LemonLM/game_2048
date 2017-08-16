#include "Game.h"
#include <iostream>
using namespace std;
#include <ctime>

int map[4][4] = {0};

Game::Game(void)
{
	
}


Game::~Game(void)
{
}

void Game::show()
{
	cout << "*************************"<< endl;
	cout << "*  " << map[0][0] << "  *  " << map[0][1] << "  *  " <<  map[0][2] <<  "  *  " << map[0][3] << "  *" << endl;
	cout << "*************************"<< endl;
	cout << "*  " << map[1][0] << "  *  " << map[1][1] << "  *  " <<  map[1][2] <<  "  *  " << map[1][3] << "  *" << endl;
	cout << "*************************"<< endl;
	cout << "*  " << map[2][0] << "  *  " << map[2][1] << "  *  " <<  map[2][2] <<  "  *  " << map[2][3] << "  *" << endl;
	cout << "*************************"<< endl;
	cout << "*  " << map[3][0] << "  *  " << map[3][1] << "  *  " <<  map[3][2] <<  "  *  " << map[3][3] << "  *" << endl;
	cout << "*************************"<< endl;

	cout << "操作详情： （请按下方显示键值进行游戏）" << endl;
	cout << "a:  左移      d:  右移" << endl;
	cout << "w:  上移      s:  下移" << endl;
	cout << "p:  结束" << endl;
}

int Game::random_num()
{
	srand((unsigned int)time(NULL));
	int num = rand() % 10;
	return num < 1 ? 4 : 2;
}

void Game::random_place()
{
	int row ,col;
	row = rand() % 4;
	col = rand() % 4;
	while(map[row][col] != 0)
	{
		row = rand() % 4;
		col = rand() % 4;
	}
	map[row][col] = random_num();
}

void Game::moveUp()
{
	int flag,temp;
	for(int col = 0;col < 4;col++)
	{
		for(int row = 0;row < 4;row++)
		{
			if(map[row][col] != 0)
			{
				flag = row;
				while(flag != 0 && map[flag-1][col] == 0)
				{
					temp = map[flag-1][col];
					map[flag-1][col] = map[flag][col];
					map[flag][col] = temp;
					flag--;
				}
			}
		}
	}
	for(int col = 0;col < 4;col++)
	{
		for(int row = 0;row < 3;row++)
		{
			if(map[row][col] == map[row+1][col])
			{
				map[row][col] *= 2;
				map[row+1][col] = 0;
			}
		}
	}
	for(int col = 0; col < 4;col++)
	{
		for(int row = 0;row < 4;row++)
		{
			if(map[row][col] != 0)
			{
				flag = row;
				while(flag != 0 && map[flag-1][col] == 0)
				{
					temp = map[flag-1][col];
					map[flag-1][col] = map[flag][col];
					map[flag][col] = temp;
					flag--;
				}
			}
		}
	}
	random_place();
}

void Game::moveDown()
{
	int flag,temp;
	for(int col = 0;col < 4;col++)
	{
		for(int row = 3;row >= 0;row--)
		{
			if(map[row][col] != 0)
			{
				flag = row;
				while(flag != 3 && map[flag+1][col] == 0)
				{
					temp = map[flag+1][col];
					map[flag+1][col] = map[flag][col];
					map[flag][col] = temp;
					flag++;
				}
			}
		}
	}
	for(int col = 0;col < 4;col++)
	{
		for(int row = 3;row > 0;row--)
		{
			if(map[row][col] == map[row-1][col])
			{
				
				map[row][col] *= 2;
				map[row-1][col] = 0;
			}
		}
	}
	for(int col = 0; col < 4;col++)
	{
		for(int row = 3;row >= 0;row--)
		{
			if(map[row][col] != 0)
			{
				flag = row;
				while(flag != 3 && map[flag+1][col] == 0)
				{
					temp = map[flag+1][col];
					map[flag+1][col] = map[flag][col];
					map[flag][col] = temp;
					flag++;
				}
			}
		}
	}
	random_place();

}

void Game::moveLeft()
{
	int flag,temp;
	for(int row = 0;row < 4;row++)
	{
		for(int col = 0;col < 4;col++)
		{
			if(map[row][col] != 0)
			{
				flag = col;
				while(flag != 0 && map[row][flag-1] == 0)
				{
					temp = map[row][flag-1];
					map[row][flag-1] = map[row][flag];
					map[row][flag] = temp;
					flag--;
				}
			}
		}
	}
	for(int row = 0;row < 4;row++)
	{
		for(int col = 0;col < 3;col++)
		{
			if(map[row][col] == map[row][col+1])
			{
				map[row][col] *= 2;
				map[row][col+1] = 0;
			}
		}
	}
	for(int row = 0; row < 4;row++)
	{
		for(int col = 0;col < 4;col++)
		{
			if(map[row][col] != 0)
			{
				flag = col;
				while(flag != 0 && map[row][flag-1] == 0)
				{
					temp = map[row][flag-1];
					map[row][flag-1] = map[row][flag];
					map[row][flag] = temp;
					flag--;
				}
			}
		}
	}
	random_place();
}

void Game::moveRight()
{
	int flag,temp;
	for(int row = 0;row < 4;row++)
	{
		for(int col = 3;col >= 0;col--)
		{
			if(map[row][col] != 0)
			{
				flag = col;
				while(flag != 3 && map[row][flag+1] == 0)
				{
					temp = map[row][flag+1];
					map[row][flag+1] = map[row][flag];
					map[row][flag] = temp;
					flag++;
				}
			}
		}
	}
	for(int row = 0;row < 4;row++)
	{
		for(int col = 3;col > 0;col--)
		{
			if(map[row][col] == map[row][col-1])
			{
				
				map[row][col] *= 2;
				map[row][col-1] = 0;
			}
		}
	}
	for(int row = 0; row < 4;row++)
	{
		for(int col = 3;col >= 0;col--)
		{
			if(map[row][col] != 0)
			{
				flag = col;
				while(flag != 0 && map[row][flag+1] == 0)
				{
					temp = map[row][flag+1];
					map[row][flag+1] = map[row][flag];
					map[row][flag] = temp;
					flag++;
				}
			}
		}
	}
	random_place();
}