class Solution {
public:
    int bit[100002];
    int createSortedArray(vector<int>& instructions) {
        memset(bit,0,sizeof(bit));
        int res = 0;
        int n = instructions.size();
        int MOD = 1e9 + 7;
        for(int i = 0 ; i < n;i++) {
            res = (res + min(get(instructions[i] - 1) , i - get(instructions[i]))) % MOD;
            update(instructions[i]);
        }
        return res;
    }
    void update(int x) {
        while( x < 100002) {
            bit[x] ++;
            x+= (x &  (-x));
        }
    }
    int get(int x) {
        int res = 0;
        while(x > 0) {
            res += bit[x];
            x -= (x &(-x));
        }
        return res;
    }
};