int findWays(vector<int>& arr, int k)

{
	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,0));
	for(int i=0;i<n;i++){
		dp[i][0]=1;
	}
	if(arr[0]<=k)
	dp[0][arr[0]]=1;

	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
		int take,nottake;
		take=nottake=0;
		if(arr[i]<=j){
			take=dp[i-1][j-arr[i]];
		}
		nottake=dp[i-1][j];
		dp[i][j]=take+nottake;
		}
	}
	int ans=dp[n-1][k];

	return (ans%1000000007);
}
