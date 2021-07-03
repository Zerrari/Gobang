int check_rows(int (*)[9]);
int check_columns(int (*)[9]);
int check_diags(int (*)[9]);
int check(int (*)[9]);

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
