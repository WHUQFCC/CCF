#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f;

int main()
{
	int n,a,ans=INF;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(vector<int>::iterator it=v.begin();it<v.end()-1;it++)
	{
		if(ans>*(it+1)-*it)
			ans=*(it+1)-*it;
	}
	cout<<ans<<endl;
	return 0;
}
 
