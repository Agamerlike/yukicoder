#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

int crypt(int num)
{
	int ret=0;
	while(1)
	{
		ret=0;
		while(num!=0)
		{
			ret+=num%10;
			num/=10;
		}
		if(ret<10)
			break;
		else
			num=ret;
	}
	return ret;
}

bool prime[200005];

int main()
{
	int n,k;
	vector<pair<int,int>> kou;
	int ans=0;
	cin>>k>>n;
	//エラトステネスのふるい
	fill(prime,prime+200005,true);
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<200005;i++)
	{
		if(prime[i])
		{
			for(int j=i*2;j<200005;j+=i)
				prime[j]=false;
		}
	}
	//k以上n以下の範囲の素数とそのハッシュを取り出す
	for(int i=k;i<n+1;i++)
	{
		if(prime[i])
			kou.push_back(make_pair(i,crypt(i)));
	}
	
	bool f[10];//0から9までどのくらい使われたか
	int cnt=0;//最大カウント
	int pos=0;//最大の最初の位置
	int i=0;
	/*
	for(int i=0;i<kou.size();i++)
		cerr<<kou[i].first<<" "<<kou[i].second<<endl;*/
	int c=0;
	int p=i;
	fill(f,f+10,false);
	while(i<kou.size())
	{
		//cerr<<p<<" "<<c<<endl;
		while(!f[kou[i].second])
		{
			f[kou[i].second]=true;
			c++;
			i++;
			if(i==kou.size())
				break;
		}
		if(c>=cnt)
		{
			cnt=c;
			pos=p;
		}
		//しゃくとり
		if(i<kou.size())
		{
			for(int j=p;j<i+1;j++)
			{
				f[kou[j].second]=false;
				c--;
				if(kou[j].second==kou[i].second)
				{
					p=j+1;
					break;
				}
			}
		}
	}
	cout<<kou[pos].first<<endl;
	return 0;
}