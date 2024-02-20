class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left(0), right(nums.size() - 1);
        while(left <= right) {
            //找到左边和val相等的元素;
            while (left <= right && nums[left] != val) {
                left++;
            }
            //找到右边不等于val的元素
            while (left <= right && nums[right] == val) {
                right--;
            }
            //交换left和right的元素
            if (left <= right) {
                swap(nums[left],nums[right]);
            }
        }
        return left;
    }
};
