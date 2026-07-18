#include <cmath>
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num1 = to_string(low);
        string num2 = to_string(high);
        int n = num1.size();
        int m = num2.size();
        char l = num1[0];
        char h = num2[0];
        vector<int> result;
        for(int i = n; i <= m; ++i){
            char start = '1';
            if(i == n) start = l;
            char end = '9';
            if(i == m) end = h;
            for(char j = start; j <= end; ++j){
                string ans_s = "";
                for(char ch = j; ch <= j + i - 1; ++ch){
                    if(ch > '9'){
                        ans_s = to_string(INT_MAX);
                        break;
                    }
                    ans_s += ch;
                }
                int ans = stoi(ans_s);
                if(ans >= low && ans <= high) result.push_back(ans);
            }
        }
        return result;
    }
};