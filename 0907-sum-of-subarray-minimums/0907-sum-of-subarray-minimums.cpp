class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long ans = 0;

        stack<int> st;

        for (int i = 0; i <= n; i++) {
            
            while (!st.empty() && 
                   (i == n || arr[st.top()] >= arr[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long contribution =
                    1LL * arr[mid] *
                    (mid - left) *
                    (right - mid);

                ans = (ans + contribution) % mod;
            }

            st.push(i);
        }

        return ans;
    }
};