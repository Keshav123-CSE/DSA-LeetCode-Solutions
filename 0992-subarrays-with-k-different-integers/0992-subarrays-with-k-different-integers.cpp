class Solution {
public:

    int atMost(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        
        int l = 0;
        int count = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            
            freq[nums[r]]++;
            
            while (freq.size() > k) {
                
                freq[nums[l]]--;
                
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                
                l++;
            }
            
            count += r - l + 1;
        }
        
        return count;
    }

    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};