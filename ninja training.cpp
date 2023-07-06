//recussrion method of the problem

int fun(int day,int last,vector<vector<int>> &points){
    if(day==0){
        int point=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                point=max(point,points[0][i]);
            }
        }
        return point;
    }
    int point=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            
            point=max(point,points[day][i]+fun(day-1,i,points));
        }
    }
    return point;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
int ans=fun(n-1,3,points);

return ans;
}

//Dynamic prograing method top down approach

int fun(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(dp[day][last]!=-1)
    return dp[day][last];
    
    if(day==0){
        int point=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                point=max(point,points[0][i]);

            }
        }
        return point;
    }
    int point=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            
            point=max(point,points[day][i]+fun(day-1,i,points,dp));
        }
    }
    dp[day][last]=point;
    return point;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>>dp(n,vector<int>(4,-1));
int ans=fun(n-1,3,points,dp);

return ans;
}

//bottom up approach
