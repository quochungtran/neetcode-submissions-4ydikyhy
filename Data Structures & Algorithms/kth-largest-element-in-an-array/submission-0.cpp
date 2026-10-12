class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k){
        int pivot = nums[right];
        int p = left;

        for (int i = left; i < right; i++){
            if (nums[i] <= pivot){
                swap(nums[p], nums[i]);
                p++;
            }
        }

        swap(nums[p], nums[right]);

        if (p == k){
            // we have already p-1 elements which smaller than pivot and pivot is actually
            // kth largest element
            return nums[p];
        }
        else if (p < k){
            return quickSelect(nums, p+1, right, k);
        }
        else if (p > k){
            return quickSelect(nums, left, p-1, k);
        }
    }
};
