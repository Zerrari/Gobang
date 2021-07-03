#include <iostream>
#include <string>
#include "prog.h"

std::string player1;
std::string player2;

void cursor_movement(int,int,int (*)[9],int);
int generate(int,int,int (*)[9]);
void set_position(int,int,int);

void player()
{
	std::cout << "Input 1st player name:" << std::endl;
	getline(std::cin,player1);
	std::cout << player1 << std::endl;

	std::cout << "Input 2st player name:" << std::endl;
	getline(std::cin,player2);
	std::cout << player2 << std::endl;
}




void set_position(int xpos,int ypos,int flag)
{
	system("clear");
	//std::cout << player1 << "          VS          " << player2 << std::endl;
	for (int i = 1;i < 10;i++)
	{
		for (int j = 1;j < 10;j++)
		{
			if (i == xpos && j == ypos)
			{
				if (flag == 1)
				{
					xy_pos[i][j] = 1;
					std::cout << "| o ";
				}
				else
				{
					xy_pos[i][j] = -1;
					std::cout << "| • ";
				}
			}
			else if(xy_pos[i][j] == 1)
			{
				std::cout << "| o ";
			}
			else if(xy_pos[i][j] == -1)
			{
				std::cout << "| • ";
			}
			else
				std::cout << "|   ";
		}
		std::cout << "|";
		std::cout <<'\n';
	}
	return;
}

int main(int argc,char* argv[])
{
	for (int x = 0;x < 9;x++)
	{
		for (int y = 0;y < 9;y++)
		{
			xy_pos[x][y] = 0;
		}
	}
	if (argc == 1)
	    {
		    player();
		    generate(1,1,xy_pos);
		    cursor_movement(xpos,ypos,xy_pos,flag);
	    }
	else if (argc == 2)
	{
		printf("Use wsad to move\n");
		printf("Type enter to mark\n");
		printf("Type q to quit\n");
		player();
	}
	else
	    {
		    std::cout << "error" << std::endl;
	    }
	return 0;
}
