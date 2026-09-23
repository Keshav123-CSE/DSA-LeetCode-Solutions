class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen[0] = -1;
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if (seen.count(rem)) {
                if (i - seen[rem] >= 2)
                    return true; // length >= 2
            } else {
                seen[rem] = i;
            }
        }
        return false;
    }
};