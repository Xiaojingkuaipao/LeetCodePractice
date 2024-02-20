class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 1;
        int pre_dif = 0;
        if (nums.size() == 1) {
            return 1;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            //考虑平坡和单调序列有平坡的现象，条件里面有等于0是因为有平坡，predif更新放在if里面是因为有单调平坡
            int dif = nums[i + 1] - nums[i];
            if ((pre_dif <= 0 && dif > 0) || (pre_dif >= 0 && dif < 0)) {
                result += 1;
                pre_dif = dif;
            }
        }
        return result;
    }
};

