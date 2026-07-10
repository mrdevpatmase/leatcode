class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxSum = INT_MIN, currSum = 0;
       int n = nums.size();

       for (int i = 0; i < n; i++){
        if(currSum < 0){
            currSum = 0;
        }
        currSum += nums[i];

        maxSum = max(maxSum,currSum);
       }
    return maxSum;
    }

};