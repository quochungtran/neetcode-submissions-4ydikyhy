class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // we compare the last element and first element of numbers and compare to target.
        // the current smallest and biggest element we are currently validate
        // we pair them and can remove the candidate from left and right, we dont need to 

        int l = 0, r = numbers.size() - 1;

        while (l < r){
            auto currSum = numbers[l] + numbers[r];
            if (currSum == target){
                return {l+1, r+1};
            }
            else if (currSum < target){
                l++;
            }
            else{
                r--;
            }
        }
        return {-1, -1};
    }
};
