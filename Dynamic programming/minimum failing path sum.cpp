// tabulation
class Solution {
public:
 int fun(int i,int j,vector<vector<int>> & matrix){
     if(j<0 || j>=matrix[0].size() || i<0)
     return 1e4;

     if(i==0)
     return matrix[0][j];

     int left,right,straight;
    
     straight=matrix[i][j]+fun(i-1,j,matrix);
      left=matrix[i][j]+fun(i-1,j-1,matrix);
     right=matrix[i][j]+fun(i-1,j+1,matrix);

     return min(left,min(right,straight));
 }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n,m;
       n=matrix.size();
       m=matrix[0].size();

       vector<vector<int>> dp(n,vector<int> (m,0));
       for(int i=0;i<m;i++){
              dp[0][i]=matrix[0][i];
       }
       for(int i=1;i<n;i++){
              for(int j=0;j<m;j++){
                     int left,right,straight;
                     left=right=straight=INT_MAX;
                     if(j>0){
                            left=matrix[i][j]+dp[i-1][j-1];
                     }
                     straight=matrix[i][j]+dp[i-1][j];
                     if(j<m-1){
                     right=matrix[i][j]+dp[i-1][j+1];

                     }

              dp[i][j]=min(left,min(right,straight));
              }
       }
       int ans=INT_MAX;
       for(int j=0;j<m;j++){
ans=min(ans,dp[n-1][j]);
       }
       return ans;
    }
};

//recurssion
class Solution {
public:
 int fun(int i,int j,vector<vector<int>> & matrix){
     if(j<0 || j>=matrix[0].size() || i<0)
     return 1e4;

     if(i==0)
     return matrix[0][j];

     int left,right,straight;
    
     straight=matrix[i][j]+fun(i-1,j,matrix);
      left=matrix[i][j]+fun(i-1,j-1,matrix);
     right=matrix[i][j]+fun(i-1,j+1,matrix);

     return min(left,min(right,straight));
 }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int i,j;
       i=matrix.size();
       j=matrix[0].size();
int ans=INT_MAX;
       for(int k=0;k<j;k++ ){
ans=min(ans,fun(i-1,k,matrix));
       }

       return ans;
    }
};
