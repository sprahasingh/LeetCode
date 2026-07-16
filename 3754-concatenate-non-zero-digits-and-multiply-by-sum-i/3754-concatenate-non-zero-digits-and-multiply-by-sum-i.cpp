class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = n;
        int sum = 0;
        string s = "";
        while(num){
            int d = num % 10;
            sum += d;
            if(d != 0) s += to_string(d);
            num /= 10;
        }
        if(s.empty()) return 0;
        reverse(s.begin(), s.end());
        long long x = stoll(s);
        return 1LL*x*sum;
    }
};