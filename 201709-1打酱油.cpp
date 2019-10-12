#include <iostream>
using namespace std;

int main()
{
	int ans=0,re=0,a;
	int n;
	cin>>n;
	n/=10;
	ans+=n;
	while(n>=5)
	{
		n-=5;
		re+=2;
	}
	while(n>=3)
	{
		n-=3;
		re+=1;
	}
	ans+=re;
	cout<<ans<<endl;
	return 0;
}
