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
	int dx[]={0,1,0,-1};
	int dy[]={1,0,-1,0};//上右下左の順番
	for(int i=0;i<4;i++)
	{
		if(x+dx[i]<w && x+dx[i]>-1 && y+dy[i]>-1 && y+dy[i]<h)
		{
			if(m[y+dy[i]][x+dx[i]]==n && make_pair(y+dy[i],x+dx[i])!=goal)
			{
				check[y+dy[i]][x+dx[i]]=true;
				q.push_back(make_pair(y+dy[i],x+dx[i]));
			}
		}
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
		for(int i=0;i<4;i++)
		{
			int ax=x+dx[i];
			int ay=y+dy[i];
			if(ax<w && ax>-1 && ay>-1 && ay<h)
			{
				if(m[ay][ax]==n && !check[ay][ax])
				{
					check[ay][ax]=true;
					q.push_back(make_pair(ay,ax));
				}
			}
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
				ans+=bfs(i,j,i,j+1,m[i][j]);
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