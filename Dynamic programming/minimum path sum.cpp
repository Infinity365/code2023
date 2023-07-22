//space optimized
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n,m;
        n=grid.size();
        m=grid[0].size();
       // vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>cur(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                cur[j]=grid[i][j];

                else{
                    int left,right;
left=right=INT_MAX;
                    if(i>0){
                        left=grid[i][j]+prev[j];
                    }
                    if(j>0){
                        right=grid[i][j]+cur[j-1];
                    }
                    cur[j]=min(left,right);
                }
            }
            prev=cur;
        }
        return prev[m-1];
    }
};

//tabulation
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=grid[i][j];
            }
            else{
            
                int left,right;
                left=right=grid[i][j];
                if(i>0)
                left+=dp[i-1][j];
                else
                left+=1e9;
                
                if(j>0)
                right+=dp[i][j-1];
                else
                right+=1e9;
                
                dp[i][j]=min(left,right);
            
        }}
    }
    return dp[n-1][m-1];
}

//recussion
#include <bits/stdc++.h> 
int fun(int i,int j,vector<vector<int>> &grid){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0)
    return 1e6;

    int left,right;
    //left=right=0;
    
    left=grid[i][j]+fun(i-1,j,grid);
    right=grid[i][j]+fun(i,j-1,grid);

    return min(left,right);
}
int minSumPath(vector<vector<int>> &grid) {
   int n=grid.size();
   int m=grid[0].size();

   return fun(n-1,m-1,grid);
}
