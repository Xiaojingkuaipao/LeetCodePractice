class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int sublength = 0;
        int result = INT_MAX;
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            //注意这里要用while循环而不是单单一个if，就比如窗口前端有两个1，但是你最后加上一个10，你就可能多次更新窗口的起始位置
            while (sum >= target) {
                sublength = end - start + 1;
                result = min(result, sublength);
                sum -= nums[start];
                start++;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
