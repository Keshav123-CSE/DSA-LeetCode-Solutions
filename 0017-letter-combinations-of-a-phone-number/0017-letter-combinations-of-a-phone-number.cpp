class Solution {
public:

vector<string> result;
      
        vector<string> phone={
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
        void solve(int index, string& nums, string& temp) {
            if (index == nums.size()){
            result.push_back(temp);
            return;
        }
        string letters = phone[nums[index] - '0'];
        for (char ch : letters) {
            temp.push_back(ch);
            solve(index+1, nums, temp);
            temp.pop_back();
        }
        }

          vector<string> letterCombinations(string nums) {
            if(nums.empty())
            return {};
            string temp;
           
            solve(0, nums, temp);
            return result;
          }
           
        
};
          

        





     