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

vector<Edge> g[10001];
priority_queue<P,vector<P>,greater<P>> que;
bool used[10001];
int dist[10001];

int main()
{
	int n;
	int ans;
	cin>>n;
	//それぞれのマスから到達できるマスに辺を張る
	for(int i=1;i<n+1;i++)
	{
		int cnt=0;
		for(int j=0;j<16;j++)
		{
			if((i&(int)pow(2,j))>0)
				cnt++;
		}
		if(i-cnt>0)
			g[i].push_back(Edge(i-cnt,1));
		
		if(i+cnt<n+1)
			g[i].push_back(Edge(i+cnt,1));
	}
	fill(used,used+n+1,false);
	//ここからダイクストラ
	fill(dist,dist+n+1,(int)1e9-1);
	dist[1]=0;
	que.push(P(0,1));
	while(!que.empty())
	{
		P p=que.top(); que.pop();
		int v=p.second;
		if(dist[v]<p.first)
			continue;
		for(int i=0;i<g[v].size();i++)
		{
			Edge e=g[v][i];
			if(dist[e.to]>dist[v]+e.cost)
			{
				dist[e.to]=dist[v]+e.cost;
				que.push(P(dist[e.to],e.to));
			}
		}
	}
	//ここまでダイクストラ
	if(dist[n]==(int)1e9-1)
		ans=-1;
	else
		ans=dist[n]+1;
	cout<<ans<<endl;
	return 0;
}