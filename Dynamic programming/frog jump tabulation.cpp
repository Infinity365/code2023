#include <bits/stdc++.h> 
int fun(int ind,vector<int> &dp,vector<int> &height){
    if(dp[ind]!=-1)
    return dp[ind];
    for(int i=1;i<=ind;i++){
        int left=dp[i-1]+abs(height[i]-height[i-1]);
        int right=INT_MAX;
        if (i > 1) {
          right = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i]=min(left,right);
    }
    return dp[ind];
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    dp[0]=0;
  
    return fun(n-1,dp,heights);
}
