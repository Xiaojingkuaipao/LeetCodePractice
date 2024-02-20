class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //因为这个数组是按照非递减顺序排列的，每个元素平方之后最大的一定在两端，所以有了双指针法
        int left = 0;
        int right = nums.size() - 1;
        vector<int>result(nums.size(), 0);
        int k = nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                result[k] = nums[right] * nums[right];
                right--;
            } 
            else {
                result[k] = nums[left] * nums[left];
                left++;
            }
            k--;
        }
        return result;
    }
};
