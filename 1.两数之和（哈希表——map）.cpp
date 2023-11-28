class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
      //哈希表，用于存放两个关键字，一个是元素，一个是索引
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash.find(target - nums[i]);//map的find函数，找到对应key，并返回迭代器，如果没有则返回end()
            if (it != hash.end()){
                return {i,it->second};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
