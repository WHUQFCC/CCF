#include <iostream>
using namespace std;

struct student
{
	int num;
	int pos;
}stu[1005];

int main()
{
	int n,k;
	cin>>n;
	cin>>k;
	for(int i=0;i<n;i++)
	{
		stu[i].num=i+1;
		stu[i].pos=i;
	}
	for(int i=0;i<k;i++)
	{
		int a,b,c;
		cin>>a>>b;
		c=stu[a-1].pos+b;
		if(b>0)
			for(int i=0;i<n;i++)
				if(stu[i].pos>stu[a-1].pos && stu[i].pos<=c)
					stu[i].pos--;
		if(b<0)
			for(int i=0;i<n;i++)
				if(stu[i].pos<stu[a-1].pos && stu[i].pos>=c)
					stu[i].pos++;					
		stu[a-1].pos+=b;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(stu[j].pos==i)
			{
				cout<<stu[j].num<<" ";
				break;
			}
	cout<<endl;
	return 0;
}
