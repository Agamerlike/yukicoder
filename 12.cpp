#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
bool isprime[5000001];//ふるい
vector<int> prime;
vector<vector<int>> primenum;//それぞれの素数に使われている数字

bool eq(bool a[],bool b[])
{
	for(int i=0;i<10;i++)
	{
		if(a[i]!=b[i])
			return false;
	}
	return true;
}

int main()
{
	int n;
	bool a[10];
	bool s[10];
	int ans=-1;
	int primecnt=0;
	cin>>n;
	fill(a,a+10,false);
	fill(s,s+10,false);
	for(int i=0;i<n;i++)
	{
		int aa;
		cin>>aa;
		a[aa]=true;
	}

	//エラトステネスのふるい
	fill(isprime,isprime+5000001,true);
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i<5000001;i++)
	{
		if(isprime[i])
		{
			for(int j=i*2;j<5000001;j+=i)
				isprime[j]=false;
		}
	}
	for(int i=0;i<5000001;i++)
	{
		if(isprime[i])
		{
			prime.push_back(i);
			vector<int> v;
			int p=i;
			while(p!=0)
			{
				v.push_back(p%10);
				p/=10;
			}
			primenum.push_back(v);
			primecnt++;
		}
	}
	//ここから解答
	int i=0;
	while(i<primecnt+1)
	{
		int j=i;//最初の素数
		while(i<primecnt+1)
		{
			bool f=false;
			for(int k=0;k<primenum[i].size();k++)
			{
				s[primenum[i][k]]=true;
				if(!a[primenum[i][k]])
					f=true;
			}
			if(eq(s,a))
			{
				int ret=0;
				if(i==primecnt-1)
				
					ret+=5000000;
				else
					ret+=(prime[i+1]-1);
				
				if(j==0)
					ret-=1;
				else
					ret-=(prime[j-1]+1);
				
				ans=max(ret,ans);
				//cerr<<prime[j]<<" "<<prime[i]<<endl;
			}
			i++;
			//終了条件
			if(f)
			{
				fill(s,s+10,false);
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}