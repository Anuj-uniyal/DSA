class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        long long maxi = nums.back();
        for(int i=nums.size()-2;i>=0;--i) {
            if(nums[i] <= maxi) {
                maxi = nums[i];
            }else {
                long long k = (nums[i] + maxi - 1) / maxi;
                ans+=k-1;
                maxi=nums[i]/k;
            }
        }
        return ans;
    }
};