#include <stdio.h>

#define N 1005

int a[N][N];

int main()
{
	int n;
	scanf("%d",&n);
	int num[n+1];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		for(int j=0;j<num[i];j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	int sum[n];
	int c[n];
	for(int i=0;i<n;i++)
	{
		c[i]=0;
		sum[i]=0;
	}
			
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<num[i];j++)
		{
			if(a[i][j]>0)
			{
				if(sum[i]>a[i][j])
					c[i]=1;
				sum[i]=a[i][j];
			}
			else 
				sum[i]+=a[i][j];
		}
	}
	
	int T=0;
	int D=0;
	int E=0;
	
	for(int i=0;i<n;i++)
	{
		T+=sum[i];
		if(c[i]==1)
			D++;
	}
	
	for(int i=0;i<n;i++)
	{
		if(i==n-2 && c[n-2]==1 && c[n-1]==1 && c[0]==1)
			E++;
		else if(i==n-1 && c[0]==1 && c[n-1]==1 && c[1]==1)
			E++;
		else if(c[i]==1 && c[i+1]==1 && c[i+2]==1)
			E++;
	}
	
	printf("%d %d %d",T,D,E);
	
	return 0;
 }  
