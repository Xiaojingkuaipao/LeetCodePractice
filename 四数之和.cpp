class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            //一级剪枝，注意这个剪枝，因为这个没有规定数组的正负，所以如果这个数大于target，再加上一个负数也可以小于它，只有在nums[k] > 0 && target > 0的时候才可以用nums[k] > target剪枝
            if (nums[k] > target && nums[k] > 0 && target > 0){
                break;
            }
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                if (nums[k] + nums[i] > target && nums[k] + nums[i] > 0&& target > 0) {
                    break;
                }
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long a = (long)nums[k] + nums[i] + nums[left] + nums[right];
                    if (a == target) {
                        result.push_back({nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])left++;
                        while (left < right && nums[right] == nums[right - 1])right--;
                        left++;
                        right--;
                    } 
                    else if (a < target) {
                        left++;
                    } 
                    else{
                        right--;
                    }
                    
                }
            }
        }
        return result;
    }
};
