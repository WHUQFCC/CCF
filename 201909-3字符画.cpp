#include <iostream>
#include <string>
using namespace std;

typedef struct
{
	int r,g,b;
}Pix;

string pi[1085][1925];
Pix pix1[1085][1925];
Pix pix2[1085][1925];
int m,n,p,q;

void hextoDec(char a,char b,int &c)
{
	c=0;
	switch(a)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':c+=(a-'0')*16;break;
		case 'a':c+=10*16;break;
		case 'b':c+=11*16;break;
		case 'c':c+=12*16;break;
		case 'd':c+=13*16;break;
		case 'e':c+=14*16;break;
		case 'f':c+=15*16;break;
	}
	switch(b)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':c+=(b-'0');break;
		case 'a':c+=10;break;
		case 'b':c+=11;break;
		case 'c':c+=12;break;
		case 'd':c+=13;break;
		case 'e':c+=14;break;
		case 'f':c+=15;break;
	}
}

void stringtoint()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			hextoDec(pi[i][j][1],pi[i][j][2],pix1[i][j].r);
			hextoDec(pi[i][j][3],pi[i][j][4],pix1[i][j].g);
			hextoDec(pi[i][j][5],pi[i][j][6],pix1[i][j].b);
		}
}

void getFinalPix()
{
	for(int i=0;i<n/q;i++)
		for(int j=0;j<m/p;j++)
			for(int k=0;k<q;k++)
				for(int l=0;l<p;l++)
				{
					pix2[i][j].r+=pix1[q*i+k][p*j+l].r;
					pix2[i][j].g+=pix1[q*i+k][p*j+l].g;
					pix2[i][j].b+=pix1[q*i+k][p*j+l].b;
				}
	for(int i=0;i<n/q;i++)
		for(int j=0;j<m/p;j++)
		{
			pix2[i][j].r/=p*q;
			pix2[i][j].g/=p*q;
			pix2[i][j].b/=p*q;
		}
}

void trans(int pixValue)
{
	int a;
	char b;
	if(pixValue>=100)
	{
		a=pixValue/100;
		b=a+'0';
		cout<<"\\x3"<<b;
	}
	if(pixValue>=10)
	{
		a=pixValue%100;
		a/=10;
		b=a+'0';
		cout<<"\\x3"<<b;
	}
	a=pixValue%10;
	b=a+'0';
	cout<<"\\x3"<<b;
	
}

void show()
{
	for(int i=0;i<n/q;i++)
	{
		for(int j=0;j<m/p;j++)
		{
			if(j!=0)
				if(pix2[i][j].r==pix2[i][j-1].r && pix2[i][j].g==pix2[i][j-1].g && pix2[i][j].b==pix2[i][j-1].b) 
				{
					cout<<"\\x20";
					continue;
				}		
			cout<<"\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";
			trans(pix2[i][j].r);
			cout<<"\\x3B";
			trans(pix2[i][j].g);
			cout<<"\\x3B";
			trans(pix2[i][j].b);
			cout<<"\\x6D\\x20";
		}
		if(n/q!=1 && i==n/q-1)
			cout<<"\\0A";
	}
	cout<<"\\x1B\\x5B\\x30\\x6D\\x0A";
}

int main()
{
	cin>>m>>n;
	cin>>p>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>pi[i][j];
			if(pi[i][j].size()==2)
			{
				string s=pi[i][j];
				pi[i][j]="#######";
				pi[i][j][1]=s[1];
				pi[i][j][2]=s[1];
				pi[i][j][3]=s[1];
				pi[i][j][4]=s[1];
				pi[i][j][5]=s[1];
				pi[i][j][6]=s[1];
			}
			if(pi[i][j].size()==4)
			{
				string s=pi[i][j];
				pi[i][j]="#######";
				pi[i][j][1]=s[1];
				pi[i][j][2]=s[1];
				pi[i][j][3]=s[2];
				pi[i][j][4]=s[2];
				pi[i][j][5]=s[3];
				pi[i][j][6]=s[3];
			}
		}
	for(int i=0;i<n/q;i++)
		for(int j=0;j<m/p;j++)
		{
			pix2[i][j].r=0;
			pix2[i][j].g=0;
			pix2[i][j].b=0;
		}
	stringtoint();
	getFinalPix();
	show();
	return 0;
}
