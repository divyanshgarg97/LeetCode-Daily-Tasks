class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // my logic is to make graph and then bfs from beginWord to endWord and find the ans
        // do bfs for answer
        // endWord should exist in wordList
        // when moving from one word to another we can check every character one by one by changing it
        set<string> s; // O(n) worst case
        for(auto i : wordList) s.insert(i); // O(n) 
        if(s.find(endWord) == s.end()) return 0; // O(1)
        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        while(!q.empty()){ // O(n)
            int sz = q.size();
            for(int i = 0 ;i < sz;i++) {
                string f = q.front();
                q.pop();
                if(f == endWord) {
                    return ans+1;
                }
                else{
                    for(int j = 0 ;j < f.length();j++) { // O(w)
                        string temp = f;
                        for(char k = 'a' ; k <= 'z' ; k++ ){ // O(26)
                            temp[j] = k;
                            if(s.find(temp) != s.end()) {
                                q.push(temp);
                                s.erase(temp);
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};