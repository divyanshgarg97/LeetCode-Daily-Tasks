class Solution {
public:
    long long int binpow(long long int a, long long int b,long long int m) {
        a %= m;
        long long int res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
    int concatenatedBinary(int n) {
        long long int ans = n;
        int cntdigits= 0;
        ans = 0;
        for(int i = 1; i <=n ;i++) {
            int noOfDigits = log2(i) + 1;
            ans = (ans * binpow(2,noOfDigits,1000000007));
            ans %= 1000000007;
            ans += i;
            ans %= 1000000007;
        }
        return ans;
        // int tempn = n;
        // while( tempn > 0) {
        //     cntdigits++;
        //     tempn/=2;
        // }
        // for(int i = n - 1; i >= 1; i--) {
        //     int temp = i;
        //     while(temp > 0) {
        //         int last = temp%2;
        //         temp/=2;
        //         if(last == 0) {}
        //         else{
        //             long long int addthis = (binpow(2,cntdigits,1000000007) * last);
        //             addthis %= 1000000007;
        //             ans += addthis;
        //             ans %= 1000000007;
        //             //ans = ans + (pow(2,cntdigits) * last);
        //             //ans = ans % 1000000007;
        //         }
        //         cntdigits++;
        //     }
        // }
        // return (int)ans;
    }
};