#include <iostream>

int generate(int,int,int (*)[9]);

int generate(int xpos,int ypos,int (*xy_pos)[9])
{
  system("clear");
  //std::cout << player1 << "          VS          " << player2 << std::endl;
  for (int i = 1;i < 10;i++)
    {
      for (int j = 1;j < 10;j++)
	{
		if (i == xpos && j == ypos)
			std::cout << "| x ";
		else if (xy_pos[i][j] == 1)
		{
			std::cout << "| o ";
		}
		else if (xy_pos[i][j] == -1)
		{
			std::cout << "| • ";
		}
		else
			std::cout << "|   ";
	}
      std::cout << "|";
      std::cout <<'\n';
    }
    return 0;
}
