class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
              //这里使用n而不是nums.size()是因为内置函数要重新调用，时间复杂度过高
                for (int j = i + 1; j < n; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                n--;
            }
        }
        return n;
    }
};
