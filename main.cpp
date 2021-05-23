#include <iostream>
#include <string>
#include "prog.h"
#include <termios.h>
#include <unistd.h>

void cursor_movement(int,int);
void set_position(int,int,int);
int generate(int,int);
int getch(void);
int check_rows(int (*)[9]);
int check_columns(int (*)[9]);
int check_diags(int (*)[9]);
int check(int (*)[9]);
int check_exist(int,int);
int quitgame();

int quitgame()
{
	std::cout << "Do you want to quit the game?(y/n)" << std::endl;
	char ch;
	std::cin >> ch;
	int val = 0;
	while (!val)
	{
	switch (ch){
	case 'y':
		return 1;
	case 'n':
		return 0;
	default:
		break;
	    }
	}
	return 0;
}

int check_exist(int xpos,int ypos)
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			if (xpos == i && ypos == j)
			{
				if (xy_pos[i][j] != 0)
					return 0;
				else
					return 1;
			}
		}
	}
	return 1;
}

int check_rows(int (*xy_pos)[9])
{
	int x_nums;
	int y_nums;
	for (int i = 0;i < 9;i++)
	{
		x_nums = 0;
		y_nums = 0;
		for (int j = 0;j < 9;j++)
		{
			if (xy_pos[i][j] == 1)
			{
				x_nums++;
				y_nums = 0;
			}
			else if (xy_pos[i][j] == -1)
			{
				x_nums = 0;
				y_nums++;
			}
			else
			{
				x_nums = 0;
				y_nums = 0;
			}
			if (x_nums == 5)
				return 1;
			if (y_nums == 5)
				return -1;
		}
	}
	return 0;
}

int check_columns(int (*xy_pos)[9])
{
	int x_nums;
	int y_nums;
	for (int i = 0;i < 9;i++)
	{
		x_nums = 0;
		y_nums = 0;
		for (int j = 0;j < 9;j++)
		{
			if (xy_pos[j][i] == 1)
			{
				x_nums++;
				y_nums = 0;
			}
			else if (xy_pos[j][i] == -1)
			{
				x_nums = 0;
				y_nums++;
			}
			else
			{
				x_nums = 0;
				y_nums = 0;
			}
			if (x_nums == 5)
				return 1;
			if (y_nums == 5)
				return -1;
		}
	}
	return 0;

}

int check_diags(int (*xy_pos)[9])
{
	int x_nums;
	int y_nums;
	for (int i = 0;i < 9;i++)
	{
		int temp = i + 1;
		if (xy_pos[0][i] == 1)
		{
			x_nums = 1;
			y_nums = 0;

		}
		else if (xy_pos[0][i] == -1)
		{
			x_nums = 0;
			y_nums = 1;
		}
		else
		{
			x_nums = 0;
			y_nums = 0;
		}
		for (int j = 1;j < 9;j++)
		{
			if (xy_pos[j][temp] == 1)
			{
				x_nums++;
				y_nums = 0;
			}
			else if (xy_pos[j][temp] == -1)
			{
				x_nums = 0;
				y_nums++;
			}
			else
			{
				x_nums = 0;
				y_nums = 0;
			}
			if (x_nums == 5)
				return 1;
			if (y_nums == 5)
				return -1;
			temp++;
		}
	}
	for (int i = 0;i < 9;i++)
	{
		int temp = i+1;
		if (xy_pos[i][0] == 1)
		{
			x_nums = 1;
			y_nums = 0;

		}
		else if (xy_pos[i][0] == -1)
		{
			x_nums = 0;
			y_nums = 1;
		}
		else
		{
			x_nums = 0;
			y_nums = 0;
		}
		for (int j = 1;j < 9;j++)
		{
			if (xy_pos[temp][j] == 1)
			{
				x_nums++;
				y_nums = 0;
			}
			else if (xy_pos[temp][j] == -1)
			{
				x_nums = 0;
				y_nums++;
			}
			else
			{
				x_nums = 0;
				y_nums = 0;
			}
			if (x_nums == 5)
				return 1;
			if (y_nums == 5)
				return -1;
			temp++;
		}
	}
	return 0;
}

int check(int (*xy_pos)[9])
{
	int res = 0;
	if ((res = check_rows(xy_pos)) != 0)
		return res;
	if ((res = check_columns(xy_pos)) != 0)
		return res;
	if ((res = check_diags(xy_pos)) != 0)
		return res;
	return res;
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void cursor_movement(int i,int j)
{
	char command;
	int res = 0;
	while (res == 0)
	{
		command = getch();
		switch (command){
		case 'w' :
			i--;
			if (i == 0)
			{
				i++;
				generate(i,j);
				// printf("movement error\n");
				continue;
			}
			generate(i,j);
			break;
		case 'a':
			j--;
			if (j == 0)
			{
				j++;
				generate(i,j);
				// printf("movement error\n");
				continue;
			}
			generate(i,j);
			break;
		case 's':
			i++;
			if (i == 10)
			{
				i--;
				generate(i,j);
				// printf("movement error\n");
				continue;
			}
			generate(i,j);
			break;
		case 'd':
			j++;
			if (j == 10)
			{
				j--;
				generate(i,j);
				// printf("movement error\n");
				continue;
			}
			generate(i,j);
			break;
		case 'q':
			if (quitgame())
			{
				return;
			}
			break;
		case '\n':
				if (check_exist(i,j))
				{
					set_position(i,j,flag);
					flag = -flag;
				}
				break;
		default:;
	    }
	    res = check(xy_pos);
	}
	if (res == 1)
		printf("1 Win");
	else
		printf("-1 Win");
	return;
}

void set_position(int xpos,int ypos,int flag)
{
	system("clear");
	for (int i = 1;i < 10;i++)
	{
		for (int j = 1;j < 10;j++)
		{
			if (i == xpos && j == ypos)
			{
				if (flag == 1)
				{
					xy_pos[i][j] = 1;
					std::cout << "| 1 ";
				}
				else
				{
					xy_pos[i][j] = -1;
					std::cout << "|-1 ";
				}
			}
			else if(xy_pos[i][j] == 1)
			{
				std::cout << "| 1 ";
			}
			else if(xy_pos[i][j] == -1)
			{
				std::cout << "|-1 ";
			}
			else
				std::cout << "|   ";
		}
		std::cout << "|";
		std::cout <<'\n';
	}
	return;
}


int generate(int xpos,int ypos)
{
  system("clear");
  for (int i = 1;i < 10;i++)
    {
      for (int j = 1;j < 10;j++)
	{
		if (i == xpos && j == ypos)
			std::cout << "| x ";
		else if (xy_pos[i][j] == 1)
		{
			std::cout << "| 1 ";
		}
		else if (xy_pos[i][j] == -1)
		{
			std::cout << "|-1 ";
		}
		else
			std::cout << "|   ";
	}
      std::cout << "|";
      std::cout <<'\n';
    }
    return 0;
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
		    generate(1,1);
		    cursor_movement(xpos,ypos);
	    }
	else if (argc == 2)
	{
		printf("Use wsad to move\n");
		printf("Type enter to mark\n");
		printf("Type q to quit\n");
	}
	else 
	    {
		    std::cout << "error" << std::endl;
	    }
	return 0;
}
