class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int r=0;
        int maxlen=1;
        int maxi=1;
        for(int r=0;r<n-1;r++){
            if(nums[r]<nums[r+1]){
                maxlen++;
            }else{
                maxi=max(maxi,maxlen);
                maxlen=1;
            }
        }
        return max(maxi,maxlen);
    }
};