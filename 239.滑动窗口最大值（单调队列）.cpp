class Solution {
public:
    class MyQueue{
        public:
        deque<int> que;//使用deque
        //注意pop的定义，传入一个数据，当队头的元素是这个元素的时候才删除，否则不删除
        void pop(int value) {
            if (!que.empty() && que.front() == value) {
                que.pop_front();
            }
        }
        //注意push的定义方式，为了满足单调性，没有必要维护之前的比他小的元素
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front() {
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        MyQueue q;
        //前k个元素入队
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        result.push_back(q.front());
        //开始滑动窗口，在程序运行的过程中要先把上一个窗口中的队头pop，然后push进来最新的值
        for (int i = k; i < nums.size(); i++) {
            q.pop(nums[i - k]);
            q.push(nums[i]);
            result.push_back(q.front());
        }
        return result;
    }
};
