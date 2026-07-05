class Solution {
public:
    struct Node {
        int len;
        long long sum;    
        int link;
        map<int, int> children;
    };

    long long getSum(vector<int>& nums) {
        int n = nums.size();
        vector<Node> tree(2);
        // root -1: len -1, link to itself
        tree[0].len = -1; tree[0].link = 0; tree[0].sum = 0;
        // root 0: len 0, link to root -1
        tree[1].len = 0; tree[1].link = 0; tree[1].sum = 0;

        int last = 1;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        long long best = LLONG_MIN;
        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            s[i] = nums[i];
            int cur = last;

            while (true) {
                int curLen = tree[cur].len;
                int idx = i - curLen - 1;
                if (idx >= 0 && s[idx] == s[i]) break;
                cur = tree[cur].link;
            }

            bool exists = tree[cur].children.count(s[i]);
            int curLen = tree[cur].len;

            if (!exists) {
                tree.push_back(Node());
                int newNode = tree.size() - 1;
                tree[newNode].len = curLen + 2;

                if (tree[newNode].len == 1) {
                    tree[newNode].link = 1;
                } else {
                    int tmp = tree[cur].link;
                    while (true) {
                        int tmpLen = tree[tmp].len;
                        int idx2 = i - tmpLen - 1;
                        if (idx2 >= 0 && s[idx2] == s[i]) break;
                        tmp = tree[tmp].link;
                    }
                    tree[newNode].link = tree[tmp].children[s[i]];
                }

                tree[cur].children[s[i]] = newNode;
            }

            last = tree[cur].children[s[i]];
            int L = tree[last].len;
            long long sum = prefix[i + 1] - prefix[i + 1 - L];
            tree[last].sum = sum;
            best = max(best, sum);
        }

        return best;
    }
};