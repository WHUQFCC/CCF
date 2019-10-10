#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	int x;
	int y;
}Point;

int main()
{
	int N;
	cin>>N;
	int ans=0;
	int a,b;
	Point po;
	vector<Point> H;
	vector<Point> W;
	for(int i=0;i<N;i++)
	{
		cin>>a>>b;
		while(a!=b)
		{
			po.x=a;
			po.y=a+1; 
			H.push_back(po);
			a++;
		}
	}
	for(int i=0;i<N;i++)
	{
		cin>>a>>b;
		while(a!=b)
		{
			po.x=a;
			po.y=a+1; 
			W.push_back(po);
			a++;
		}
	}
	
	int cap=H.size();
	Point poi[cap];
	int i=0;
	for(vector<Point>::iterator it=H.begin();it<H.end();it++)
	{
		poi[i].x=it->x;
		poi[i].y=it->y;
		i++;
	}

	for(vector<Point>::iterator it=W.begin();it<W.end();it++)
	{
		for(int j=0;j<cap;j++)
		{
			if(it->x==poi[j].x && it->y==poi[j].y)
				ans++;
		}
	}
	
	cout<<ans<<endl;
	return 0;
 } 
