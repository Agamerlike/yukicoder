#include <iostream>
#include <vector>

using namespace std;
using ll=long long;

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    ll n,m;
    ll ans=-1;
    cin>>n>>m;
    ll g=gcd(n,m);
    n/=g;m/=g;

    if(m==1)
    {
        while(n%10==0)
            n/=10;
        ans=n%10;
        if(ans<0)
            ans+=10;
    }else{
        ll cnt2=0;
        ll cnt5=0;
        while(m%2==0)
        {
            m/=2;
            cnt2++;
        }
        while(m%5==0)
        {
            m/=5;
            cnt5++;
        }
        if(m==1)
        {
            n%=(ll)1e12;
            for(ll i=0;i<cnt2;i++)
            {
                n*=5;
                n%=(ll)1e12;
            }
            for(ll i=0;i<cnt5;i++)
            {
                n*=2;
                n%=(ll)1e12;
            }
            while(n%10==0)
                n/=10;
            ans=n%10;
            if(ans<0)
                ans+=10;
        }
    }
    cout<<ans<<endl;
    return 0;
}