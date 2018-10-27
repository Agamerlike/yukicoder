#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <string.h>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int m[100][100];
int w,h;
int dfs(int n,int x,int y,int sx,int sy,bool check[][100],int cnt)
{
	bool cc[100][100];
	memcpy(cc,check,sizeof(bool)*10000);
	check[y][x]=true;
	int ret=0;
	if(cnt>1)
		check[sy][sx]=false;
	if(x<w-1 && m[y][x+1]==n && !check[y][x+1])
	{
		if(x+1==sx && y==sy)
			ret++;
		else
			ret += dfs(n,x+1,y,sx,sy,check,cnt+1);
	}
	if(x>0 && m[y][x-1]==n && !check[y][x-1])
	{
		if(x-1==sx && y==sy)
			ret++;
		else
			ret+=dfs(n,x-1,y,sx,sy,check,cnt+1);
	}
	if(y<h-1 && m[y+1][x]==n && !check[y+1][x])
	{
		if(x==sx && y+1==sy)
			ret++;
		else
			ret+=dfs(n,x,y+1,sx,sy,check,cnt+1);
	}
	if(y<h+1 && m[y-1][x]==n && !check[y-1][x])
	{
		if(x==sx && y-1==sy)
			ret++;
		else
			ret+=dfs(n,x,y-1,sx,sy,check,cnt+1);
	}
	return ret;
}

int main()
{
	int ans=0;
	cin>>w>>h;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			cin>>m[i][j];
	}

	//それぞれの数字について探索する
	for(int n=1;n<1001;n++)
	{
		bool check[100][100];
		//fill(check[0],check[100],false);
		//始点を探索する
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(m[i][j]==n)
				{
					fill(check[0],check[100],false);
					ans+=dfs(n,j,i,j,i,check,0);
				}
				if(ans>0)
				{
					cout<<"possible"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"impossible"<<endl;
	return 0;
}