#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int,int,int> T;
typedef long long ll;
ll MOD = 1e9+7;
int l[200][200];
bool f[200][200];
int main()
{
	int n,v,ox,oy;
	deque<T> q;//現在の座標x,y、残りレベルl
	int ans=0;
	cin>>n>>v>>ox>>oy;
	ox--;oy--;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>l[i][j];
	}
	fill(f[0],f[200],false);
	//ここからBFS
	q.push_back(make_tuple(0,0,v));
	while(!q.empty())
	{
		cerr<<q.size()<<endl;
		T t=q.front();q.pop_front();
		int x=get<0>(t);
		int y=get<1>(t);
		int zan=get<2>(t);
		f[x][y]=true;
		//ゴールまでたどり着いた場合
		if(x==n-1 && y==n-1)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		//上下左右調べる
		if(y>0 && !f[x][y-1])
		{
			int z=zan-l[x][y-1];
			if(y-1==oy && x==ox)
				z*=2;
			if(z>=0)
				q.push_back(T(x,y-1,z));
		}
		if(y<n-1 && !f[x][y+1])
		{
			int z=zan-l[x][y+1];
			if(y+1==oy && x==ox)
				z*=2;
			if(z>=0)
				q.push_back(T(x,y+1,z));
		}
		if(x>0 && !f[x-1][y])
		{
			int z=zan-l[x-1][y];
			if(y==oy && x-1==ox)
				z*=2;
			if(z>=0)
				q.push_back(T(x-1,y,z));
		}
		if(x<n-1 && !f[x+1][y])
		{
			int z=zan-l[x+1][y];
			if(y==oy && x+1==ox)
				z*=2;
			if(z>=0)
				q.push_back(T(x+1,y,z));
		}
	}
	cout<<"NO"<<endl;
	return 0;
}