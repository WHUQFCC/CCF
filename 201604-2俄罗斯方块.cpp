#include <iostream>
using namespace std;

struct point
{
	int x,y;
}pit[4];

int board[20][15];

int main()
{
	for(int i=0;i<15;i++)
		for(int j=0;j<10;j++)
			cin>>board[i][j];
	int a;
	int b=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			cin>>a;
			if(a==1)
			{
				pit[b].y=i;
				pit[b++].x=j;
			}
		}
	int lis;
	cin>>lis;		
	for(int i=0;i<4;i++)
		pit[i].x+=(lis-1);
	while(true)
	{
		if(pit[0].y==14 || pit[1].y==14 || pit[2].y==14 || pit[3].y==14)
		{
			for(int i=0;i<4;i++)
			board[pit[i].y][pit[i].x]=1;
			break;
		}

		if(board[pit[0].y+1][pit[0].x]==1 || board[pit[1].y+1][pit[1].x]==1 || board[pit[2].y+1][pit[2].x]==1 || board[pit[3].y+1][pit[3].x]==1)
		{
			for(int i=0;i<4;i++)
				board[pit[i].y][pit[i].x]=1;
			break;
		}
		else
		{
			for(int i=0;i<4;i++)
				pit[i].y++;
		}	
	}	
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<10;j++)
			cout<<board[i][j]<<" ";	
		cout<<endl;
	}
	return 0;
}

