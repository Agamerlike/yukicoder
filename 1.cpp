#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> T;//時間、所持金、座標

class Edge
{
	public:
	int cost;
	int time;
	int from;
	int to;

	Edge(int n,int t,int c)
	{
		to=n;
		time=t;
		cost=c;
	}

	Edge(int f,int t,int tt,int c)
	{
		from=f;
		to=t;
		time=tt;
		cost=c;
	}
};

vector<Edge> g[50];
int dp[50][300];
int ss[1500];
int tt[1500];
int yy[1500];
int mm[1500];
int main()
{
	int n,c,m;
	cin>>n>>c>>m;
	for(int i=0;i<m;i++)
	{
		cin>>ss[i];
		ss[i]--;
	}
	for(int i=0;i<m;i++)
	{
		cin>>tt[i];
		tt[i]--;
	}
	for(int i=0;i<m;i++)
		cin>>yy[i];
	for(int i=0;i<m;i++)
		cin>>mm[i];
	for(int i=0;i<m;i++)
	{
		g[ss[i]].push_back(Edge(tt[i],mm[i],yy[i]));
	}

	//ここからダイクストラ
	fill(dp[0],dp[50],1e9-1);
	dp[0][c]=0;
	priority_queue<T,vector<T>,greater<T>> que;
	que.push(make_tuple(0,c,0));
	while(!que.empty())
	{
		T cp=que.top();que.pop();
		int now=get<2>(cp);
		int zan=get<1>(cp);
		int lap=get<0>(cp);
		//cerr<<now<<endl;
		for(int i=0;i<g[now].size();i++)
		{
			Edge e=g[now][i];
			if(zan-e.cost>=0)
			{
				if(lap+e.time<dp[e.to][zan-e.cost])
				{
					dp[e.to][zan-e.cost]=lap+e.time;
					que.push(make_tuple(lap+e.time,zan-e.cost,e.to));
				}
			}
		}
	}
	//ダイクストラ終了
	sort(dp[n-1],dp[n-1]+300);
	if(dp[n-1][0]==1e9-1)
		cout<<-1<<endl;
	else
		cout<<dp[n-1][0]<<endl;
	return 0;
}