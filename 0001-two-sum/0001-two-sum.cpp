class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int,int> st;

        for (int i = 0; i<nums.size(); i++) {
            int second = target - nums[i];
            if(st.find(second) != st.end()) {

                return {st[second], i};
            }
            st[nums[i]] = i;

        }
        return {};
    }
};
