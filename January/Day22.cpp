class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(auto i : word1) hash1[i - 'a'] ++;
        for(auto i : word2) hash2[i-'a']++;
        vector<int> hash11(word1.length() + 1,0);
        vector<int> hash22(word1.length() + 1, 0);
        for(int i = 0 ;i < 26; i++) {
            if(hash1[i] != 0 && hash2[i]!= 0) continue;
            else if(hash1[i] == 0 && hash2[i] == 0) continue;
            else return false;
        }
        for(int i = 0 ;i < 26; i++) {
            hash11[hash1[i]]++;
            hash22[hash2[i]]++;
        }
        for(int i = 0 ;i < word1.length() + 1; i++) {
            if(hash11[i] != hash22[i]) return false;
        }
        return true;
        
    }
};