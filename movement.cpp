#include <iostream>
#include <termios.h>
#include <unistd.h>

void cursor_movement(int,int,int (*)[9],int);
int check_exist(int,int,int (*)[9]);
int getch(void);
int quitgame(void);
int check(int (*)[9]);
int generate(int,int,int (*)[9]);
void set_position(int,int,int);

int quitgame(void)
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

int check_exist(int xpos,int ypos,int (*xy_pos)[9])
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

void cursor_movement(int i,int j,int (*xy_pos)[9],int flag)
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
				generate(i,j,xy_pos);
				// printf("movement error\n");
				continue;
			}
			generate(i,j,xy_pos);
			break;
		case 'a':
			j--;
			if (j == 0)
			{
				j++;
                generate(i,j,xy_pos);
				// printf("movement error\n");
				continue;
			}
            generate(i,j,xy_pos);
			break;
		case 's':
			i++;
			if (i == 10)
			{
				i--;
                generate(i,j,xy_pos);
				// printf("movement error\n");
				continue;
			}
            generate(i,j,xy_pos);
			break;
		case 'd':
			j++;
			if (j == 10)
			{
				j--;
                generate(i,j,xy_pos);
				// printf("movement error\n");
				continue;
			}
            generate(i,j,xy_pos);
			break;
		case 'q':
			if (quitgame())
			{
				return;
			}
			break;
		case '\n':
			if (check_exist(i,j,xy_pos))
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
		std::cout << "1" << "Win" << std::endl;
	else
		std::cout << "2" << "Win" << std::endl;
	return;
}
