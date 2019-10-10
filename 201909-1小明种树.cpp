#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);//为了加快cin cout 的效率 
	
	int N,M,a;
	int T=0,k,P=0;
	int p,q=0;
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		q=0;
		for(int j=0;j<M+1;j++)
		{
			cin>>a;
			T+=a;
			if(j>0)
			{
				q+=a;	
			}
		}
		if(P>q)
		{
			P=q;
			k=i+1;
		}
	}
	P=0-P;
	
	cout<<T<<" "<<k<<" "<<P<<endl;
	return 0;
}
