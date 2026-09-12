class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxFreq = 0;
        int maxLen = 0;

        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;

            maxFreq = max(maxFreq, mp[s[r]]);

            int len = r - l + 1;

            if (len - maxFreq > k) {
                mp[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};