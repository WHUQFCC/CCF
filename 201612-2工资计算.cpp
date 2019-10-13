#include <iostream>
using namespace std;

int main()
{
	int salary;
	int t,over,tax=0;
	cin>>t;
	over=t-3500;
	if(over>0)
	{
		if(over>=1455)
			tax+=1500*0.03;
		else
			tax+=over*0.03/0.97;
		over-=1455;
	}
	if(over>0)
	{
		if(over>=2700)
			tax+=3000*0.1;
		else
			tax+=over*0.1/0.9;
		over-=2700;
	}
	if(over>0)
	{
		if(over>=3600)
			tax+=4500*0.2;
		else
			tax+=over*0.2/0.8;
		over-=3600;
	}
	if(over>0)
	{
		if(over>=19500)
			tax+=26000*0.25;
		else
			tax+=over*0.25/0.75;
		over-=19500;
	}
	if(over>0)
	{
		if(over>=14000)
			tax+=20000*0.3;
		else
			tax+=over*0.3/0.7;
		over-=14000;
	}
	if(over>0)
	{
		if(over>=16250)
			tax+=25000*0.35;
		else
			tax+=over*0.35/0.65;
		over-=16250;
	}
	if(over>0)
	{
		tax+=over*0.45/0.55;
	}
	salary=t+tax;
	cout<<salary<<endl;
	return 0;
}
