class Solution {
public:
    int characterReplacement(string s, int k) {
        // condition to create a sub string with repeated characters:
        // length(s) - max_freq_of_any_char(substring) < k 
        // -> track the current of length of substr

        unordered_map<char, int> freq;
        int maxFreq = 0;
        int r = 0;
        int l = 0;
        int result = 0;
        int n = s.size();
        while (r < n){
            freq[s[r]]++;
            // maxFreq
            maxFreq = max(maxFreq, freq[s[r]]);
            while (r - l + 1 - maxFreq > k){
                freq[s[l]]--;
                maxFreq = max(maxFreq, freq[s[l]]);
                l++;
            } 
            result = max(result, r - l + 1);
            r++;
        }
        return result;
    }
};

// A A B A B B A
    //  l     
    //        r

// freq A: 3  B: 2 , k = 1
// maxFreq = 3
// result = 4
