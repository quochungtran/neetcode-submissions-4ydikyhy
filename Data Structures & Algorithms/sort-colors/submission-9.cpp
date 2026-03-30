class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int i = 0;

        while (i <= r){ // we need to include the case i == r since the current i not yet checked 
            if (nums[i] == 0){
                swap(nums[i], nums[l]);
                i++;
                l++;
            }
            else if (nums[i] == 2){
                // nums[i] is swapped need to be checked after
                swap(nums[i], nums[r]);
                r--;
            }
            else{
                i++;
            }
        }
    }
};