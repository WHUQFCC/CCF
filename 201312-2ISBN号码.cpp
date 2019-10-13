#include <iostream>
#include <string>
using namespace std;

int main()
{
	string  isbn;
	cin>>isbn; 
	int sum=0;
	int factor=0;//每次相乘的因子 
	for(int i=0;i<11;i++)
	{
		if(i==1 || i==5)	continue;
		factor++;
		sum+=( isbn[i]-'0')*factor;
	}
	sum%=11;
	if(sum==( isbn[12]-'0') || (sum==10 &&  isbn[12]=='X'))
		cout<<"Right"<<endl;
	else
	{
		if(sum==10)
			 isbn[12]='X';
		else
			 isbn[12]=sum+'0';
		cout<< isbn<<endl;
	}
	return 0;
 } 
