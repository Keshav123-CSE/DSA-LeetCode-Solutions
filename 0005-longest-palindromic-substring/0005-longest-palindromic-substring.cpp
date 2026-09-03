

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        
        // Helper function to expand outward around indices (left, right)
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Length of the palindrome found
            int length = right - left - 1;
            if (length > maxLength) {
                maxLength = length;
                start = left + 1; // Left shifted one extra step during the loop
            }
        };

        for (int i = 0; i < s.length(); i++) {
            expand(i, i);     // Odd-length palindromes (e.g., "aba" center 'b')
            expand(i, i + 1); // Even-length palindromes (e.g., "abba" center "bb")
        }

        return s.substr(start, maxLength);
    }
};