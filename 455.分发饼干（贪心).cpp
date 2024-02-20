class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        int i = 0;
      //注意下面的边界条件，孩子和饼干都不能越界
        for (int j = 0; j < s.size() && i < g.size(); j++) {//每次循环相当于拿出来一个饼干，然后找合适的孩子
            if (g[i] > s[j]) {
                continue;
            }
            else {
                result++;
                i++;
            }
        }
        return result;
    }
};
