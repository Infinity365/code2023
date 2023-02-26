class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool ci;
        int n=nums.size();
        for(int i=0;i<n;i++){
           // ci=nums[i]-1;
            while(nums[i]>0 && nums[i]<n && nums[i]!=nums[nums[i]-1]){
                swap(nums[nums[i]-1],nums[i]);
                //ci=nums[i]-1;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }

        return n+1;
    }
};
