class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& panda) {
        int n = panda.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            
            while (!st.empty() && st.top() <= panda[i % n]) {
                st.pop();
            }


            if (i < n) {
                result[i] = st.empty() ? -1 : st.top();
            }

          
            st.push(panda[i % n]);
        }

        return result;
    }
};