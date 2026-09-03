#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLength = 1;
        int n = s.length();

        // 1. Pick every possible starting position
        for (int i = 0; i < n; i++) {
            // 2. Pick every possible ending position
            for (int j = i; j < n; j++) {
                
                // 3. Check if s[i...j] is a palindrome using basic array indexing
                bool isPalindrome = true;
                int left = i;
                int right = j;

                while (left < right) {
                    if (s[left] != s[right]) {
                        isPalindrome = false;
                        break; // Stop checking if characters don't match
                    }
                    left++;
                    right--;
                }

                // If valid and longer than previous best, update results
                int currentLength = j - i + 1;
                if (isPalindrome && currentLength > maxLength) {
                    maxLength = currentLength;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};