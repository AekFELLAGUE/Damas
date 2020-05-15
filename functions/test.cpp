#include<stdio.h>
int test(char mat[6][8], int ans)
{
	ans = 1;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if((mat[i][j] == 'O') || (mat[i][j] == 'R'))
			{
				ans = 0;
				break;
			}
		}
		if(ans == 0) break;
	}
	if(ans) return 1;
	ans = 2;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if((mat[i][j] == 'X') || (mat[i][j] == 'K'))
			{
				ans = 0;
				break;
			}
		}
		if(ans == 0) break;
	}
	return ans;
}
