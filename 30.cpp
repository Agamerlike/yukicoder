#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Edge
{
public:
  int to, from;
  ll cost;
  Edge(int n, int c)
  {
    to = n;
    cost = c;
  }
};

vector<Edge> g[100];
ll memo[100][100]; //make one i needed how many j
int n, m;

//memo[a][i]を求める
void saiki(int a)
{
	//すでに調べてあるものはもう調べなくても良い
	if(memo[a][0]>=0)
		return;
	//逆辺がないなら直接買うしかない
	if(g[a].empty())	
	{
		fill(memo[a],memo[a]+100,0);
		memo[a][a]=1;
		return;
	}

	//逆辺がある場合は調べる
	for(int i=0;i<g[a].size();i++)
	{
		Edge e=g[a][i];
		//逆辺があるものはそこに（すでに求まっているかどうか）調べに行く
		saiki(e.to);
		//求まったものに対して加算していく
		for(int j=0;j<n;j++)
		{
			//aを作るために必要なjの数 = e.cost * e.toを作るために必要なjの数
			if(memo[a][j]==-1)
				memo[a][j]=0; //初期値のままなら戻しておく
			memo[a][j]+=e.cost*memo[e.to][j];
		}
	}
	return;
}

int main()
{
  cin >> n >> m;
  fill(memo[0], memo[100], -1);
  for (int i = 0; i < m; i++)
  {
    int p, q, r;
    cin >> p >> q >> r;
    //逆辺を張る
    //JP comment, zettai abuse
    p--;
    r--;
    //memo[r][p] = q;
    g[r].push_back(Edge(p, q));
  }

	saiki(n-1);
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cerr<<memo[i][j]<<" ";
		cerr<<endl;
	}*/
  for (int i = 0; i < n - 1; i++)
    cout << memo[n - 1][i] << endl;
  return 0;
}