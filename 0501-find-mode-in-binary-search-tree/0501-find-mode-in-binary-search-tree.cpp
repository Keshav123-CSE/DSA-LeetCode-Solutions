
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> freq;
        queue<TreeNode*> q;
        q.push(root);
        int maxi = 0;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            freq[curr->val]++;
            maxi = max(maxi, freq[curr->val]);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        for (auto it : freq) {
            if (it.second == maxi)
                ans.push_back(it.first);
        }

        return ans;
    }
};
