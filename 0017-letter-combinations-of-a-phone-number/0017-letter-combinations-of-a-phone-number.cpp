class Solution {
public:

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        vector<string> mp={
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        queue<string> q;

        q.push("");

        for(char digit:digits)
        {
            int size=q.size();

            while(size--)
            {
                string cur=q.front();
                q.pop();

                for(char ch:mp[digit-'0'])
                {
                    q.push(cur+ch);
                }
            }
        }

        vector<string> ans;

        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};