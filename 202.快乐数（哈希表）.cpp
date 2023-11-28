class Solution {
public:
//求各位数的平方之和
    int getSum(int n){
        int sum = 0;
        while(n){
            sum = sum + (n%10) * (n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
      //使用map容器进行映射，因为数据过大，不能用数组进行映射，会造成很大的资源浪费，造成很高的空间复杂度
        map<int,int>hash;
        hash[n] = 1;
        while (n != 1) {
          //在这里更新n的值
            n = getSum(n);
            if (hash[n] == 1) {
                return false;
            }
            hash[n] = 1;
        }
        return true;
    }
};
