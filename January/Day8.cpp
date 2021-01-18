class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int iptr1= 0;
        int iptr2 = 0;
        int ptr1= 0;
        int ptr2= 0;
        while(ptr1 < word1.size() && ptr2 < word2.size()){
            if(word1[ptr1][iptr1] != word2[ptr2][iptr2]) return false;
            if(iptr1 == word1[ptr1].length()-1)
                ptr1++,iptr1=0;
            else
                iptr1++;
            if(iptr2 == word2[ptr2].length()-1)
                iptr2=0,ptr2++;
            else iptr2++;
               
        }
        return (ptr1 == word1.size()) && (ptr2 == word2.size());
    }
};