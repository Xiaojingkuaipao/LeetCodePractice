class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>result(n, vector<int>(n, 0));
        int loop = n / 2;  //要绕的圈数
        int num = 1; //待填充的数字
        int startx(0), starty(0);
        int end = 1;
        int i, j;
        while (loop--) {
            //填充上行
            for (j = starty; j < n - end; j++) {
                result[startx][j] = num;
                num++;
            }
            //填充右列
            for (i = startx; i < n - end; i++) {
                result[i][j] = num;
                num++;
            }
            //填充下行
            for (; j > starty; j--) {
                result[i][j] = num;
                num++;
            }
            //填充左列
            for (; i > startx; i--) {
                result[i][j] = num;
                num++;
            }
            end++;
            startx++;
            starty++;
        }
        if (n % 2) {
            result[n / 2][n / 2] = num; 
        }
        return result;
    }
};
