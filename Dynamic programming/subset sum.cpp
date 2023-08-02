//tabulation

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    
    dp[0][arr[0]]=true;

    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            int take,nottake;
            take=nottake=false;
            
            if(arr[i]<=target){
                take=dp[i-1][target-arr[i]];
            }
            nottake=dp[i-1][target];

            dp[i][target]=take|| nottake;
        }
    }
    
    return dp[n-1][k];
}

// recoursion
#include <bits/stdc++.h> 


    bool fun(vector<int>&arr,int target,int ind){
        if(target==0)
        return true;
        
        if(ind==0){
            if(target==arr[0])
            return true;
            
            else
            return false;
        }
       
        
        int take,nottake;
        take=nottake=false;
        if(arr[ind]<=target){
            take=fun(arr,target-arr[ind],ind-1);
        }
        
        nottake=fun(arr,target,ind-1);
        return take || nottake;
    }
bool subsetSumToK(int n, int k, vector<int> &arr) {
    
        
        return fun(arr,k,n-1);
}
