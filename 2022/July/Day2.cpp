// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        // find the maximum horizontal gap between any two cuts
        sort(hCuts.begin(), hCuts.end());
        int maxH = hCuts[0];
        for(int i = 1; i < hCuts.size() ;i++) {
            maxH = max(maxH, hCuts[i] - hCuts[i-1]);
        }
        maxH = max(maxH, h - hCuts[hCuts.size() - 1]);
        
        //Find the maximum vertical gap between any two cuts
        sort(vCuts.begin(), vCuts.end());
        int maxV = vCuts[0];
        for(int i =1; i < vCuts.size(); i++) {
            maxV = max(maxV, vCuts[i] - vCuts[i-1]);
        }
        maxV = max(maxV, w - vCuts[vCuts.size() - 1]);
        
        // Area between them will be the answer
        
        return int((long(maxH) * maxV % 1000000007));
    }
};