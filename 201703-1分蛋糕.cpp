#include <iostream>
using namespace std;

int cake[1005];

int main()
{
	int n,k;
	int ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>cake[i];
	}
	int j=0;
	int a=0;
	while(true)
	{
		if(j==n)	break;
		if(j==n-1 && a!=0)	ans++;
		if(a<k)
		{
			a+=cake[j++];
		 } 
		 else
		 {
		 	ans++;
		 	a=0;
		 }
	}
	cout<<ans<<endl;
	return 0;
  }  
