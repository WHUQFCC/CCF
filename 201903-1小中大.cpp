#include <iostream>
using namespace std;

int main()
{
	int max,min,middle=0;
	int n,a;
	cin>>n;
	int i=0;
	while(i<n)
	{
		cin>>a;
		if(i==0)
			max=a;
		else if(i==n-1)
			min=a;
		
		if(n%2==1)
		{
			if(i==n/2)
				middle=a;
		}
		else
		{
			if(i==n/2-1 || i==n/2)
				middle+=a;
		}
		i++;
	}
	int temp;
	double mid;
	if(max<min)
	{
		temp=max;
		max=min;
		min=temp;
	}
	int b;
	if(n%2==0)
	{
		b=middle;
		if(middle%2==0)
			middle=middle/2;
		else
			mid=(double)middle/2;
	}
		
	cout<<max<<" ";
	if(n%2==1)
		cout<<middle<<" "; 
	else if(b%2==0)
		cout<<middle<<" ";
	else
	{
		printf("%.1f ",mid);
	}
	cout<<min;
			
	return 0;
}
