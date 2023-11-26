class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};
      //将26个字母映射到hash数组中，0-25对应a-z
        if(s.size()!=t.size()){
            return false;
        }
        int n = s.size();
        for(int i = 0;i<n;i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }
        for(int i = 0;i<26;i++){
            if(hash[i]!=0){
                return false;
            }
        }
        return s!=t;
    }
};
