// tabulation
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if (i == 0 && j == 0) {

            dp[i][j] = 1;
            continue;
          }
          if (mat[i][j]== -1) {
            dp[i][j] = 0;
            continue;
          }

          else {
            int left, right;
            left = right = 0;
            if (i > 0)
              left = dp[i - 1][j];

            if (j > 0)
              right = dp[i][j - 1];

            dp[i][j] = (left + right)%mod;
          }
        }
    }
    return dp[n-1][m-1];
}
// recussion
int fun(int i, int j,vector< vector< int> > &mat){

if(i==0 &&j==0)
return 1;

if(i<0 || j<0)
return 0;

if(mat[i][j]==-1)
return 0;

int left,right;
left=right=0;
left=fun(i-1,j,mat);
right=fun(i,j-1,mat);
return left+right;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {

 return fun(n-1,m-1,mat);  
}
