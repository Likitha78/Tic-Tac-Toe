#include<stdio.h>
void display();
void game_start();
int game_end();
int turns;
int main()
{
	printf("\n\n***TIC-TAC-TOE GAME BEGINS***\n\n");
	printf("Rules:\n Player 1 plays 'O'\n Player 2 plays 'X'\n Enter in which position to be placed \n\n");
	char a[3][3]={'1','2','3','4','5','6','7','8','9'};
	display(a);
	game_start(a);
	return 0;
}

void game_start(char a[3][3])
{
	int pos,check;
	printf("Player 1:");
	scanf("%d",&pos);
	if(pos<4)
		a[0][pos-1]='O';
	else if(pos<7)
		a[1][pos-4]='O';
	else
		a[2][pos-7]='O';
	display(a);
	turns++;
	if(turns==9)
	{
		check=game_end(a);
		if(check==1) return;
		printf("\n\nDRAW\n\n***GAME ENDS***\n\n");
		return;
	}
	if(game_end(a))//
		return;
	printf("Player 2:");
	scanf("%d",&pos);
	if(pos<4)
		a[0][pos-1]='X';
	else if(pos<7)
		a[1][pos-4]='X';
	else
		a[2][pos-7]='X';
	display(a);
	turns++;
	if(game_end(a))
		return;
	if(turns==9)
	{
		int check=game_end(a);
		if(check==1) return;
		printf("\n\nDRAW\n\n***GAME ENDS***\n\n");
		return;
	}
	game_start(a);
}
int game_end(char a[3][3])
{

	int i,j,count=0;
	//checking for horizantal lines
	for(i=0;i<3;i++)
	{
		count=0;
		for(j=1;j<3;j++)
		{
			if(a[i][0]!=a[i][j]) break;
			else count=count+1;
		}
		if(count==2)
		{
			if(a[i][j-1]=='O')
				printf("\n\nPlayer 1 WINS\n\n***GAME ENDS***\n\n");
			else
				printf("\n\nPlayer 2 WINS\n\n***GAME ENDS***\n\n");
			return 1;
		}
	}
	//checking for vertical lines
	for(j=0;j<3;j++)
	{
		count=0;
		for(i=1;i<3;i++)
		{
			if(a[0][j]!=a[i][j]) break;
			else count=count+1;
		}
		if(count==2)
		{
			if(a[i-1][j]=='O')
				printf("\n\nPlayer 1 WINS\n\n***GAME ENDS***\n\n");
			else
				printf("\n\nPlayer 2 WINS\n\n***GAME ENDS***\n\n");
			return 1;
		}
	}
	//checking for diagnal lines
	if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
	{
		if(a[0][0]=='O')
			printf("\n\nPlayer 1 WINS\n\n***GAME ENDS***\n\n");
		else
			printf("\n\nPlayer 2 WINS\n\n***GAME ENDS***\n\n");
		return 1;
	}
	else if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
	{
		if(a[0][2]=='O')
			printf("\n\nPlayer 1 WINS\n\n***GAME ENDS***\n\n");
		else
			printf("\n\nPlayer 2 WINS\n\n***GAME ENDS***\n\n");
		return 1;
	}
	return 0;
}
void display(char a[3][3])
{
	printf("\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
		if(j==2)
			printf("%c",a[i][j]);
		else
			printf("%c|",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}