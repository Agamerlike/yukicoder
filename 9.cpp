#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <functional>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll MOD = 1e9+7;

int main()
{
	int n;
	priority_queue<P,vector<P>,greater<P>> aa;//レベル、戦闘回数
	int a[1500];//入力用
	int b[1500];
	int ans=1e9-1;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	
	//0から順番に時計回りに戦闘する
	for(int i=0;i<n;i++)
	{
		//init
		for(int j=0;j<n;j++)
			aa.push(make_pair(a[j],0));
		//indexは(i+j)%nで求まる
		for(int j=0;j<n;j++)
		{
			int now=(i+j)%n;
			if(now<0)
				now+=n;
			pair<int,int> c=aa.top();aa.pop();
			c.first+=b[now]/2;
			c.second++;
			aa.push(c);
		}
		//最も多かった戦闘回数を求める
		int m=0;
		while(!aa.empty())
		{
			pair<int,int> c=aa.top();aa.pop();
			m=max(m,c.second);
		}
		
		ans=min(ans,m);
	}
	cout<<ans<<endl;
	return 0;
}