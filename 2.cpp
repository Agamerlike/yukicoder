#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
int main()
{
	ll n;
	vector<int> yama;
	int ans=0;
	cin>>n;
	int cnt=0;
	while(n%2==0)
	{
		n/=2;
		cnt++;
	}
	if(cnt>0)
		yama.push_back(cnt);
	for(int i=3;i<11000;i+=2)
	{
		cnt=0;
		while(n%i==0)
		{
			n/=i;
			cnt++;
		}
		if(cnt>0)
			yama.push_back(cnt);
	}
	if(n!=1)
		yama.push_back(1);
	
	//Nim
	//xorを取る
	for(int i=0;i<yama.size();i++)
	{
		ans^=yama[i];
	}
	if(ans==0)
		cout<<"Bob"<<endl;
	else
		cout<<"Alice"<<endl;
	return 0;
}