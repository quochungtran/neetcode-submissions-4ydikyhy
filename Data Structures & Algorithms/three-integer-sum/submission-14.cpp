class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = 0;
        vector<vector<int>> ans; 
        for (int k = 0; k < nums.size(); k++){
            // skip kth duplicate, skip post index, we dont want to process the current case
            if (k > 0 && nums[k] == nums[k-1]){
                continue;
            }
                
            int i = k+1;
            int j = n-1;
            while (i < j){

                if (nums[i] + nums[j] == target - nums[k]){
                    ans.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i+1] == nums[i]){ // if next element still the same as the previous case, we skip it 
                        i += 1;
                    }
                    i++;
                    j-=1;
                }
                else if (nums[i] + nums[j] < target - nums[k]){
                    i++;
                }
                else{
                    j-=1;
                }
            }
        }

        return ans;
    }
};