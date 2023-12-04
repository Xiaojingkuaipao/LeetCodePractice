class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       int hash_r[26] = {0};
       int hash_m[26] = {0};
       for (char ch : ransomNote) {
           hash_r[(int)(ch - 'a')]++;
       }
       for (char ch : magazine) {
           hash_m[(int)(ch - 'a')]++;
       }
       for (int i = 0; i < 26; i++) {
           if(hash_m[i] < hash_r[i]) {
               return false;
           }
       }
       return true;
    }
};
