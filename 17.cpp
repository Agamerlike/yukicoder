#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

class Edge
{
	public:
	int cost;
	int from;
	int to;

	Edge(int n,int c)
	{
		to=n;
		cost=c;
	}

	Edge(int f,int t,int c)
	{
		from=f;
		to=t;
		cost=c;
	}
};

int d[50][50]; //ワーシャルフロイド
int s[50];
//start:0

int main()
{
	int n,m;
	int ans=1e8-1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	s[0]=1e8;
	s[n-1]=1e8;
	cin>>m;
	fill(d[0],d[50],1e8-1);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=c;
		d[b][a]=c;
	}
	for(int i=0;i<n;i++)
		d[i][i]=0;

	//ここからワーシャルフロイド
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}

	//始点とゴールとは異なる2点を選び、minを取る
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(i==j)
				continue;
			ans=min(ans,d[0][i]+s[i]+d[i][j]+s[j]+d[j][n-1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}