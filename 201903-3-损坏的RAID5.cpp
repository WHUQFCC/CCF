#include <iostream>
#include <string>
using namespace std;

typedef struct Disk
{
	int disknum;
	string content;
}Disk;

typedef struct
{
	int disknum;
	int posi;
}Block;

int n,s,l,m,disklenth;
Disk disk[1005];//用于存储存在的磁盘的磁盘号和该磁盘上的内容 
int block[1005];//用于存储待查询的块的块号 

Block getPosition(int blknum);//获取块在磁盘上的位置 
int sixteenPower(int power);//计算16的power次幂 
int hextoDec(char c);//将16进制字符c转化成十进制数字 
int stringtoInt(string str);//将16进制字符串str转化成十进制整型数字 
void print(int blknum);//打印块号为blknum的块的内容 

int main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>s>>l;
	for(int i=0;i<l;i++)//存现存的磁盘 
	{
		cin>>disk[i].disknum;
		cin>>disk[i].content;
	}
	disklenth=disk[0].content.size()/8;
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>block[i];
	for(int i=0;i<m;i++)
		print(block[i]);	
	return 0;	
}

Block getPosition(int blknum)
{
	int bandnum,diskn,pos,b;
	bandnum=blknum/(s*(n-1));//该块所在的行号 
	b=blknum%(s*(n-1));
	int db=n-1-bandnum%n;//db为一行中该行校验条带所在的磁盘号 
	int i=0;
	diskn=(db+1+blknum%(s*(n-1))/s)%n;//该块所在的磁盘号 
	pos=bandnum*s+blknum%s;//该块在磁盘上的位置 
	Block block;
	block.disknum=diskn;
	block.posi=pos; 
	return block;
}

int sixteenPower(int power)
{
	if(power==0)
		return 1;
	int res=1;
	for(int i=0;i<power;i++)
		res*=16;
	return res;
}

int hextoDec(char c)
{
	int ans;
	switch(c)
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
		case '9':ans=c-'0';break;
		case 'a':
		case 'A':ans=10;break;
		case 'b':
		case 'B':ans=11;break;
		case 'c':
		case 'C':ans=12;break;
		case 'd':
		case 'D':ans=13;break;
		case 'e':
		case 'E':ans=14;break;
		case 'f':
		case 'F':ans=15;break;
	}
	return ans;
}

int stringtoInt(string str)
{
	int ans=0;
	for(int i=str.size()-1,j=0;i>=0;i--,j++)//从低位到高位依次转化 
		ans+=hextoDec(str[i])*sixteenPower(j);
	return ans;
}

void print(int blknum)
{
	if(blknum>=disklenth*(n-1))//检验块号是否超过阵列的最大容量 
	{
		cout<<"-"<<endl;
		return;
	}
	Block bl=getPosition(blknum);
	for(int j=0;j<l;j++)//检验该块是否存在于已知磁盘上 
	{
		if(disk[j].disknum==bl.disknum)
		{
			string s=disk[j].content.substr(bl.posi*8,8);
			cout<<s<<endl;
			return;
		}
	}
	if(n-1>l)//若不能推导出输出"-" 
	{
		cout<<"-"<<endl;
		return;
	}
	int res=0,b=0;
	string str;
	for(int i=0;i<l;i++)//可以推导出 
	{
		str=disk[i].content.substr(bl.posi*8,8);
		if(b==0)
		{
			b++;
			res=stringtoInt(str);
			continue;
		}
		res=res^stringtoInt(str);
	}
	cout<<hex<<uppercase<<res<<endl;
}
