#include <iostream>
using namespace std;

typedef struct
{
	int x;
	bool v;//方向true为向右 
}Ball;

Ball ball[1005];
int dire[1005];//记录小球的为置 
int n,L,t;

void move(Ball &b)//小球运动函数 
{
	if(b.v==true)
	{
		dire[b.x]--;
		b.x++;
		dire[b.x]++;
	}	
	else
	{
		dire[b.x]--;
		b.x--;
		dire[b.x]++;	
	}
}

void changeDire()//小球方向改变函数 
{
	for(int i=0;i<=L;i++)
		if(dire[i]==2)
			for(int j=0;j<n;j++)
				if(ball[j].x==i)
					ball[j].v=!ball[j].v;
	
	for(int i=0;i<n;i++)
		if(ball[i].x==0 || ball[i].x==L)
			ball[i].v=!ball[i].v;
}

int main()
{
	cin>>n>>L>>t;
	for(int i=0;i<1000;i++)
		dire[i]=0;
	for(int i=0;i<n;i++)//初始化小球 
	{
		cin>>ball[i].x;
		ball[i].v=true;
		dire[ball[i].x]++;
		if(ball[i].x==L)//当小球的位置为最右边时，要改变其初始方向 
			ball[i].v=!ball[i].v;
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n;j++)
			move(ball[j]);
		changeDire();
	}
	for(int i=0;i<n;i++)
		cout<<ball[i].x<<" ";
	cout<<endl;
	return 0;
}


