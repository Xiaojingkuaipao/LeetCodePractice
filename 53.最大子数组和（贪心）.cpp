class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int tmp_result = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp_result += nums[i];
            result = max(result, tmp_result);
            if (tmp_result < 0) {
                tmp_result = 0;
            }
        }
        return result;
    }
};
