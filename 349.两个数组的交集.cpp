class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      //创建一个哈希数组，题目要求是数组中的元素最大不会超过1000，所以开辟一个1005大小的int数组
        int hash[1005] = {0};
        vector<int> ans;//返回的答案
      //先对nums1进行一个遍历，如果在hash中，hash[nums1[i]] != 0，证明出现过 
        for(int i = 0; i < nums1.size(); i++){
            hash[nums1[i]]++;
        }
      //对nums2进行一个排序操作，方面后续去重
        sort(nums2.begin(),nums2.end());
        if(hash[nums2[0]]){
            ans.push_back(nums2[0]);
        }
      //为了防止数组越界，在上面单独写nums2[0]的判断
        for(int i = 1; i < nums2.size(); i++) {
            if(nums2[i-1] != nums2[i] && hash[nums2[i]]){
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};
