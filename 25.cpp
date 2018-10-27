#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	ll n,m;
	cin>>n>>m;
	ll g=gcd(n,m);
	n/=g;
	m/=g;
	return 0;
}