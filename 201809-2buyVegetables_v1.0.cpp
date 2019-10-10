#include <iostream>
using namespace std;

const int N = 1000005;
int talk[N];

int main()
{
	for(int i=0;i<N;i++)
		talk[i]=0;
		
	int n,ans=0,a,b;
	cin>>n;
	for(int i=0;i<2*n;i++)
	{
		cin>>a>>b;
		while(a<b)
		{
			talk[a-1]++;
			a++;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		if(talk[i]==2)
			ans++;
	}
	
	cout<<ans<<endl;
	return 0;
 } 
