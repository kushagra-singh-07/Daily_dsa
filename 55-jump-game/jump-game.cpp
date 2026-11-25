
class Solution {
    vector<int> dp;

public:
    bool solve(int i, vector<int>& nums) {
        int n = nums.size();

        if(i == n-1) return true;
        if(i >= n) return false;

        if(dp[i] != -1)
            return dp[i];

        for(int j = 1; j <= nums[i]; j++) {
            if(dp[j]=solve(i+j, nums))
                return true;
        }

        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n, -1);

        return solve(0, nums);
    }
};
