class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //先对数组进行排序，方便双指针处理问题
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            if (nums[i] > 0) {// 如果第一个数就大于0了，那么后面的就全大于零了，就不用考虑了
                break;
            }
            //去重，如果这个数和数组上一次遍历的值一样就跳过，因为会出现一次一样的三元组
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    //在找到这个三元组之后，要对第二个元素以及第三个元素相同的也去重
                    //样例：[-2, 0, 0, 2, 2]
                    while (left < right && nums[left] == nums[left + 1])left++;
                    while (left < right && nums[right] == nums[right - 1])right--;
                    //找到这个三元组之后，把左指针和右指针同时收缩
                    left++;
                    right--;
                }
                else if (sum < 0) { //证明这个数字过于小，left（小指针）后移，增大sum
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        return result;
    }
};
