//recurssion

class Solution{
  public:
  int fun(int price[],int TL,int n){
      if(n==0){
          return TL*price[0];
      }
      
      int take,nottake;
      nottake=fun(price,TL,n-1);
      take=0;
      int rodlength=n+1;
      if(rodlength<=TL){
          take=price[n]+fun(price,TL-rodlength,n);
      }
      
      return max(take,nottake);
  }
    int cutRod(int price[], int n) {
        //code here
        return fun(price,n,n-1);
    }
};
//tabulation

lass Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int TL=n;
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        //base case
        for(int i=0;i<=TL;i++){
            dp[0][i]=i*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=TL;j++){
                int take,nottake;
                nottake=dp[i-1][j];
                take=0;
                int rodlength=i+1;
                if(rodlength<=j){
                    take=price[i]+dp[i][j-rodlength];
                }
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[n-1][n];
    }
};
