class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // input : x = "zxyzxyz"
        // output: zxy is longest substring without repeating substring
        
        // x = ""
        // 0

        // using hashmap to keep track the freq of current substring

        // naive solution: usigng 2 loops => O(n^2) n is length of string
        // Having 2 pointers l and r, for keep track the current longest size of sub string without dunplicated
        // for each iteration from right pointer,
        // we decide to move left pointer in case we detect the duplicated characters

        // z x y z x y z
        //         l
        //             r
        // map: z : 1 ,x : 1, y: 1, 
        // result: max(result, currSizeWindow) : 3
        // Complexity: O(n)

        int l = 0;
        int r = 0;
        int n = s.size();
        int result = 0;

        unordered_map<char, int> freq;
        while (r < n){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                if (freq[s[l]] == 0){
                    freq.erase(s[l]);
                }
                l++;
            }
            result = max(result, r - l + 1);
            r++;
        }
        return result;
    }

};
