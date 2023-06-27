https://www.codingninjas.com/studio/problems/frog-jump_3621012?leftPanelTab=1
//edit
#include <bits/stdc++.h> 
int fun(int ind,vector<int>&heights, vector<int>&dp){
    if(ind==0)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int right=INT_MAX;
    int left=fun(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    if(ind>1){
        right=fun(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    
    }
    dp[ind]=min(left,right);
    return dp[ind];
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    
    vector<int> dp(n+1,-1);
    return fun(n-1,heights,dp);
}
