#include <bits/stdc++.h> 
int fun(int i,int j)
{

}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m+1, vector<int>(n+1,0));

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0)
			dp[i][j]=1;
                        else {
                          int up, down;
                          up = down = 0;
                          if (i > 0)
                            up = dp[i - 1][j];
                          if (j > 0)
                            down = dp[i][j - 1];

                          dp[i][j] = up + down;
                        }
                                        }
	}
	return dp[m-1][n-1];
}

// space optimized
long long  numberOfPaths(int m, int n)
{
    // Code Here
    vector<int> prev(n,0);
    for(int i=0;i<m;i++){
        vector<int> cur(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
            cur[j]=1;
            
            else{
                int left,down;
                left=down=0;
                if(i>0)
                {
                    left=prev[j];
                }
                if(j>0){
                    down=cur[j-1];
                }
                cur[j]=left+down;
            }
        }
        prev=cur;
    }
    return prev[n-1];
    
}
