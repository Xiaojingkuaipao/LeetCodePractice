class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int ans = 0;
      //对数组nums1和nums2进行一次双重遍历，把所有nums1和nums2中的数字都相加一次，因为不需要key有序，所以用unordered_map就可以，key为相加得到的值，value为这个值出现的次数
        unordered_map<int,int> my_map;
        for (int a : nums1) {
            for (int b : nums2) {
                my_map[a + b]++;
            }
        }
      //对nums3和nums4进行双重遍历，以下代码自行体会
        for (int c : nums3) {
            for (int d : nums4) {
              //这里要加上map对应的value值，因为题目中需要统计的是元组的个数
                ans += my_map[-c - d];
            }
        }
        return ans;
    }
};
