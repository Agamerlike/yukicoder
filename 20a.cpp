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

vector<Edge> g[40000]; //(i/200,i%200)でやる
int d[40000];
int l[200][200];
int main()
{
	int n,v,ox,oy;
	cin>>n>>v>>ox>>oy;
	ox--;oy--;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>l[i][j];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>0)
				g[i*200+j].push_back(Edge(i*200-200+j,l[i-1][j]));
			if(i<n-1)
				g[i*200+j].push_back(Edge(i*200+200+j,l[i+1][j]));
			if(j>0)
				g[i*200+j].push_back(Edge(i*200+j-1,l[i][j-1]));
			if(j<n-1)
				g[i*200+j].push_back(Edge(i*200+j+1,l[i][j+1]));
		}
	}

	//ここからダイクストラ
	fill(d,d+40000,1e8-1);
	d[0]=0;
	priority_queue<P,vector<P>,greater<P>> q;
	q.push(P(0,0));
	while(!q.empty())
	{
		//cerr<<q.size()<<endl;
		P p=q.top();
		q.pop();
		int vv=p.second;
		if(d[vv]<p.first)
			continue;
		cerr<<vv<<" "<<d[vv]<<endl;
		for(int i=0;i<g[vv].size();i++)
		{
			Edge e=g[vv][i];
			if(d[e.to]>d[vv]+e.cost);
			{
				d[e.to]=d[vv]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
	//ここまでダイクストラ
	int stcost=d[(n-1)*200+n-1];
	int socost=1e8-1;
	int otcost=1e8-1;
	//オアシスありの場合
	if(ox!=-1)
	{
		socost=d[ox*200+oy];
		//ここからダイクストラ
		fill(d,d+40000,1e8-1);
		d[ox*200+oy]=0;
		q.push(P(0,ox*200+oy));
		while(!q.empty())
		{
			//cerr<<q.size()<<endl;
			P p=q.top();
			q.pop();
			int vv=p.second;
			if(d[vv]<p.first)
				continue;
			//cerr<<v/200<<" "<<v%200<<" "<<d[v]<<endl;
			for(int i=0;i<g[vv].size();i++)
			{
				Edge e=g[vv][i];
				if(d[e.to]>d[vv]+e.cost);
				{
					d[e.to]=d[vv]+e.cost;
					q.push(P(d[e.to],e.to));
				}
			}
		}
		//ここまでダイクストラ
		otcost=d[(n-1)*200+n-1];
	}
	if(stcost<=v)
	{
		//オアシスを経由せずにいける
		cout<<"YES"<<endl;
	}else if(otcost<=2*(v-socost)){
		//オアシスを経由していける
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}