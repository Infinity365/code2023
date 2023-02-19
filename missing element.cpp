class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=nums[0];
        int n=nums.size();
        int xor2=0;
        int i=1;
        for(i=1;i<n;i++){
            xor1^=nums[i];
            xor2^=i;
        }

        xor2^=i;
        return xor2^xor1;
    }
}
