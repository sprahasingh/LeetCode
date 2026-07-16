class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = n;
        int place = 1;
        int sum = 0;
        int x = 0;
        while(num){
            int d = num % 10;
            sum += d;
            if(d != 0){
                x += place * d;
                place *= 10;
            }
            num /= 10;
        }
        return 1LL*x*sum;
    }
};