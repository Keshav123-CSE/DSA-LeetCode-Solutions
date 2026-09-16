class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
      
        vector<int> last_seen(3, -1);

        for (int i = 0; i < n; i++) {
      
            last_seen[s[i] - 'a'] = i;

       
            int min_idx = min({last_seen[0], last_seen[1], last_seen[2]});

           
            if (min_idx != -1) {
                count += (min_idx + 1);
            }
        }

        return count;
    }
};