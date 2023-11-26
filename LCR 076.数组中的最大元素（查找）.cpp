class Solution {
public:
    int Partition(vector<int>&nums,int low, int high){
        int pivot = nums[low];
        int i = low + 1;
        for(int j = low + 1;j <= high;j++) {
            if (nums[j] < pivot) {
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[low],nums[i - 1]);
        return i - 1;
    }
    int QuickSort(vector<int>&nums, int low, int high,int k) {
        int index = Partition(nums, low, high);
        int n = nums.size();
        if(index == n-k){
            return nums[index];
        }else if (index < n-k){
            return QuickSort(nums, index+1, high,k);
        }else {
            return QuickSort(nums, low, index-1,k);
        }
        return -1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSort(nums,0,nums.size()-1,k);
    }
};
