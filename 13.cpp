#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int m[100][100];
int w,h;

int bfs(int si,int sj,int ti,int tj,int n)
{
	bool check[100][100];
	fill(check[0],check[100],false);
	deque<pair<int,int>> q;
	pair<int,int> goal=make_pair(ti,tj);
	check[si][sj]=true;
	//隣接するt以外の頂点を最初にキューに入れる
	//上下左右を探索
	int x=sj;
	int y=si;
	if(x<w-1 && m[y][x+1]==n && make_pair(y,x+1)!=goal)
	{
		check[y][x+1]=true;
		q.push_back(make_pair(y,x+1));
	}
	if(x>0 && m[y][x-1]==n && make_pair(y,x-1)!=goal)
	{
		check[y][x-1]=true;
		q.push_back(make_pair(y,x-1));
	}
	if(y<h-1 && m[y+1][x]==n && make_pair(y+1,x)!=goal)
	{
		check[y+1][x]=true;
		q.push_back(make_pair(y+1,x));
	}
	if(y<h+1 && m[y-1][x]==n && make_pair(y-1,x)!=goal)
	{
		check[y-1][x]=true;
		q.push_back(make_pair(y-1,x));
	}
	//ここからBFS
	while(!q.empty())
	{
		pair<int,int> v=q.front();
		x=v.second;
		y=v.first;
		q.pop_front();
		if(v==goal)
		{
			return 1;
		}
		//上下左右を探索
		if(x<w-1 && m[y][x+1]==n && !check[y][x+1])
		{
			check[y][y+1]=true;
			q.push_back(make_pair(y,x+1));
		}
		if(x>0 && m[y][x-1]==n && !check[y][x-1])
		{
			check[y][x-1]=true;
			q.push_back(make_pair(y,x-1));
		}
		if(y<h-1 && m[y+1][x]==n && !check[y+1][x])
		{
			check[y+1][x]=true;
			q.push_back(make_pair(y+1,x));
		}
		if(y<h+1 && m[y-1][x]==n && !check[y-1][x])
		{
			check[y-1][x]=true;
			q.push_back(make_pair(y-1,x));
		}
	}
	return 0;
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

	//始点を探索する
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			//隣接する同じ数字の組み合わせを探し、それぞれにBFS
			if(i>0 && m[i][j]==m[i-1][j])
				ans+=bfs(i,j,i-1,j,m[i][j]);
			if(i<h-1 && m[i][j]==m[i+1][j])
				ans+=bfs(i,j,i+1,j,m[i][j]);
			if(j>0 && m[i][j]==m[i][j-1])
				ans+=bfs(i,j,i,j-1,m[i][j]);
			if(j<w-1 && m[i][j]==m[i][j-1])
				ans+=bfs(i,j,i,j-1,m[i][j]);
			if(ans!=0)
			{
				//cerr<<n<<" "<<j<<" "<<i<<endl;
				cout<<"possible"<<endl;
				return 0;
			}
		}
	}
	cout<<"impossible"<<endl;
	return 0;
}