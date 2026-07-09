class Solution {
public:

    vector<string> ans;

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

    void solve(int index,string &digits,string temp)
    {
        if(index==digits.size())
        {
            ans.push_back(temp);
            return;
        }

        string letters=mp[digits[index]-'0'];

        for(char ch:letters)
        {
            temp.push_back(ch);

            solve(index+1,digits,temp);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        solve(0,digits,"");

        return ans;
    }
};