class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suffix;
    int n;

    int solve(int i, int M) {

        // No piles left
        if (i >= n)
            return 0;

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // X can be from 1 to 2*M
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            int newM = max(M, X);

            // Stones opponent can get
            int opponent = solve(i + X, newM);

            // Total stones remaining from i
            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // Suffix sum
        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};