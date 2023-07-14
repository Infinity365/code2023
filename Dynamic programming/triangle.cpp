#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.

	vector<int> dp(triangle.size(),-1);

//int n=triangle.size();
	for(int i=0;i<triangle[n-1].size();i++){
		dp[i]=triangle[n-1][i];
	}

	for(int i=n-2;i>=0;i--){
		for(int j=0;j<triangle[i].size();j++){
			dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
		}
	}
	return dp[0];
}
