class Solution {
    bool fun(int n,vector<int>& nums,int target){
        vector<vector<bool>>dp(n,vector<bool>(target+1,0));

        for(int i=0;i<n;i++){
            //when the sum is 0 it cn be formed by any set
            dp[i][0]=1;
        }
        if(nums[0]<=target){
            dp[0][nums[0]]=1;
        }

        for(int i=1;i<n;i++){
            for(int k=1;k<=target;k++){
                bool take,nottake;
                take=nottake=false;
                if(nums[i]<=k){
                    take=dp[i-1][k-nums[i]];
                }
                nottake=dp[i-1][k];
                dp[i][k]=take||nottake;

            }
        }
        return dp[n-1][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
if(sum%2!=0)
return 0;
else
return fun(n,nums,sum/2);
    }
};
