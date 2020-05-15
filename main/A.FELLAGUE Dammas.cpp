							/*			Abdelkader FELLAGUE ==>	a.fellague27@gmail.com			*/

#include<stdio.h>
#include"../functions/post.cpp"
#include"../functions/player1.cpp"
#include"../functions/player2.cpp"
#include"../functions/test.cpp"
main()
{
	char X = 'X', O = 'O', e = ' ';
	char mat[6][8] = {{e,X,e,X,e,X,e,X}, {X,e,X,e,X,e,X,e}, {e,e,e,e,e,e,e,e}, {e,e,e,e,e,e,e,e}, {e,O,e,O,e,O,e,O}, {O,e,O,e,O,e,O,e}};
	int ans = 0;
	while(ans == 0)
	{
		post(mat);
		player_1(mat);
		ans = test(mat, ans);
		post(mat);
		if((ans == 1) || (ans == 2)) break;
		player_2(mat);
		ans = test(mat, ans);
		post(mat);
		if((ans == 1) || (ans == 2)) break;
	}
	if(ans == 2) 	printf("\n\t\t\tThe winner is player 2 ( O )");
	else 			printf("\n\t\t\tThe winner is player 1 ( X )");
					printf("\n\n\t\t\t  Thanks for playing \2\n\n");
	system("pause");
}
