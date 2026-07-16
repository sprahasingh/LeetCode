class Solution {
public:
    void solve(unordered_map<int, vector<char>>& mp, vector<string>& ans, int d){
        int n = mp[d].size();
        vector<string> temp = ans;
        ans.clear();
        for(int i = 0; i < n; i++){
            char ch = mp[d][i];
            if(temp.empty()) ans.push_back(string(1, ch));
            else{
                for(int j = 0; j < temp.size(); j++){
                    ans.push_back(temp[j] + ch);
                }
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        unordered_map<int, vector<char>> mp;
        mp.reserve(8);
        char ch = 'a';
        for(int i = 2; i <= 9; ++i){
            int j = 0;
            if(i == 7 || i == 9) j = 4;
            else j = 3;
            while(j--){
                mp[i].push_back(ch++);
            }
        }
        vector<string> ans;
        for(int i = 0; i < n; ++i){
            int d = digits[i] - '0';
            solve(mp, ans, d);
        }
        return ans;
    }
};