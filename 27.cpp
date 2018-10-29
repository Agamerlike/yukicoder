#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int dp[80]; // cannot write down description of DP only English...

int main()
{
    int v[4];
    int ans=1e8-1;
    for(int i=0;i<4;i++)
        cin>>v[i];
    
    // from now DP
    for(int a=1;a<31;a++)
    {
        for(int b=a+1;b<31;b++)
        {
            for(int c=b+1;c<31;c++)
            {
                fill(dp,dp+80,1e8-1);
                dp[0]=0;
                for(int i=1;i<31;i++)
                {
                    for(int j=0;j<31;j++)
                    {
                        if(dp[j]==i-1)
                        {
                            dp[j+a]=min(dp[j+a],i);
                            dp[j+b]=min(dp[j+b],i);
                            dp[j+c]=min(dp[j+c],i);
                        }
                    }
                }
                int cnt=0;
                for(int i=0;i<4;i++)
                    cnt+=dp[v[i]];
                ans=min(ans,cnt);
            }
        }
    }
    // end of DP

    cout<<ans<<endl;
    return 0;
}