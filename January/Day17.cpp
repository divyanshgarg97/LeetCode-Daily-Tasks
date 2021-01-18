class Solution {
public:
    int ans = 0;
    int n2;
    vector<int> possible;
    void solve(int lastCharIndex,int index) {
        if(index == n2) {
            ans +=1;
            return;
        }
        for(int i = lastCharIndex ; i < possible.size();i++) {
            solve(i,index + 1);// lets put possible[i] here and move to next position
        }
    }
    int countVowelStrings(int n) {
        possible.push_back('a');
        possible.push_back('e');
        possible.push_back('i');
        possible.push_back('o');
        possible.push_back('u');
        n2 = n;
        solve(0,0);
        return ans;
    }
};