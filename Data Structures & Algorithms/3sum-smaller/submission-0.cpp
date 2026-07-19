class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n-1;
        int res=0;
        for (int k = 0; k < n; k++){
            l = k+1;
            r = n-1;
            while (l < r){
                if (nums[l] + nums[r] >= target - nums[k]){
                    r-=1;
                }
                else{
                    res += r - l;
                    l++;
                }
            }
        }

        return res;
    }
};
