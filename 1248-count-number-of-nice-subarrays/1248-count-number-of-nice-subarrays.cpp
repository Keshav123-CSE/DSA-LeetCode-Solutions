class Solution {
public:
   int atMost(vector<int>& nums, int k) {
       int n = nums.size();
      if (k<0) return 0;
      int l = 0; int r = 0; int sum = 0; int cnt = 0;

      while (r < n) {
        sum += nums[r] % 2;
        while (sum > k) {
            sum = sum - nums[l] %2;
            l = l+1;
        }
        cnt = cnt + (r-l+1); 
        r = r+1;
      }
      return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};