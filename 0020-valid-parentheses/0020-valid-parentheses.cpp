class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

           
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }

            // Closing brackets
            else {

                // No opening bracket available
                if (st.empty())
                    return false;

                // Check matching
                if ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};