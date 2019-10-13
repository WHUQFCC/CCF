#include <iostream>
using namespace std;

int data[1005];

int main()
{
	int ans;
	int n,temp,a=0,b=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>data[i];
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
			if(data[j]>data[j+1])
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
				}
	
	for(int i=0;i<n;i++)
	{
		if(data[i]>data[n/2])
			a++;
		if(data[i]<data[n/2])
			b++;
	}
	if(a==b)
		ans=data[n/2];
	else
		ans=-1;
	cout<<ans<<endl;
	return 0;		
}
