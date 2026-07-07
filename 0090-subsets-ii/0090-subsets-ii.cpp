class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& currentsums, vector<vector<int>>& result) {
        result.push_back(currentsums);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue; // skip duplicates at same level
            currentsums.push_back(nums[i]);
            solve(i + 1, nums, currentsums, result);
            currentsums.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sorting is essential for the duplicate-skip trick to work
        vector<vector<int>> result;
        vector<int> currentsums;
        solve(0, nums, currentsums, result);
        return result;
    }
};