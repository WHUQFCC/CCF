#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	bool isHaveKey; //true为有钥匙 false为没有钥匙
	int keyNum;
}Keybox;//钥匙盒结构体 

typedef struct teacher
{
	int start;//开始时间start=s 
	int end;//结束时间end=s+c 
	int keyNum;
	bool operator < (const teacher& ter)const//用于结构体排序 
	{
		return keyNum < ter.keyNum;
	}
}Teacher;//该结构体记录老师使用教室的情况 ，姑且称为老师结构体 

Keybox keybox[1005];
Teacher thr[1005];
int clock = 0;//模拟时钟 
int rtnCount = 0;//用于记录归还钥匙的次数 
int n, k;

void getKey()//取钥匙 
{
	for (int i = 0; i < k; i++)
	{
		if (clock == thr[i].start)//start=clock表明该时刻要用到钥匙 
			for (int j = 0; j < n; j++)//扫描钥匙盒寻找相应的钥匙 
				if (thr[i].keyNum == keybox[j].keyNum && keybox[j].isHaveKey == true)
				{
					keybox[j].isHaveKey = false;
					keybox[j].keyNum = 0;//没有钥匙时keyNum为0 
				}
	}
}

void returnKey()//归还钥匙 
{
	vector<Teacher> v;//用于存储同时归还钥匙的老师 
	for (int i = 0; i < k; i++)
		if (clock == thr[i].end)//end=clock表明该时刻要归还钥匙 		
			v.push_back(thr[i]);

	if (v.size() > 1)
		sort(v.begin(), v.end());//根据钥匙编号的大小排序 
	for (vector<Teacher>::iterator it = v.begin(); it < v.end(); it++)//根据钥匙编号的大小先后归还钥匙 
		for (int i = 0; i < n; i++)
			if (keybox[i].isHaveKey == false)
			{
				keybox[i].keyNum = it->keyNum;
				keybox[i].isHaveKey = true;
				rtnCount++;//每归还一次便加一 
				break;
			}
}

int main()
{
	int w, s, c;
	cin >> n >> k;
	for (int i = 0; i < n; i++)//初始化钥匙盒 
	{
		keybox[i].isHaveKey = true;
		keybox[i].keyNum = i + 1;
	}
	for (int i = 0; i < k; i++)//存入老师的使用教室信息 
	{
		cin >> w >> s >> c;
		thr[i].keyNum = w;
		thr[i].start = s;
		thr[i].end = s + c;
	}
	while (true)
	{
		clock++;//每循环一次时钟加一
		returnKey();//returnKey()和getKey()的顺序不能对调，因为题目要求先还再取 
		getKey();
		if (rtnCount == k)	break;//归还次数等于k时退出循环 
	}
	for (int i = 0; i < n; i++)
		cout << keybox[i].keyNum << " ";
	cout << endl;
	return 0;
}

