class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int x : nums1) {
            int idx = -1;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == x) { idx = j; break; }
            }
            int result = -1;
            for (int j = idx + 1; j < nums2.size(); j++) {
                if (nums2[j] > x) { result = nums2[j]; break; }
            }
            ans.push_back(result);
        }
        return ans;
    }
};