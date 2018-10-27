#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

double dp[10001];

int main()
{
	int h,a,d;
	int ans=0;
	cin>>h>>a>>d;
	fill(dp,dp+10001,-1);
	dp[0]=0.0f;
	for(int i=1;i<a+1;i++)
		dp[i]=1.0f;
	//ここからDP
	for(int i=a+1;i<h+1;i++)
	{
		double at=1.0f+dp[i-a];//通常攻撃での期待値
		double hi=1.5f+dp[max(i-d,0)];//必殺技での期待値
		dp[i]=min(at,hi);
	}
	cout<<dp[h]<<endl;
	return 0;
}