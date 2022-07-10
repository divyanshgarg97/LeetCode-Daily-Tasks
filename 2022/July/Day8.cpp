//https://leetcode.com/problems/paint-house-iii/

class Solution {
public:
    int dp[102][102][22];
    int solve(int index,int till_now,int prev_paint,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(index == m){
            if(till_now == target) return 0;
            else return INT_MAX/2;
        }
        if(till_now > target) return INT_MAX/2; //as if I return INT_MAX & it get added to someone in recursion tree than it will go overflow
        if( dp[index][till_now][prev_paint] !=-1) 
            return dp[index][till_now][prev_paint];
        int ans =INT_MAX/2;
        if(houses[index] == 0) { // If Not painted then paint it
            for(int i =1;i<=n;i++) {
                if(i == prev_paint)
                    ans = min(ans,cost[index][i-1] + solve(index+1,till_now,i,houses,cost,m,n,target));
                else
                    ans = min(ans,cost[index][i-1] + solve(index+1,till_now+1,i,houses,cost,m,n,target));
            }
        }
        else {
            if(houses[index] == prev_paint) // if already painted
                ans = min(ans,solve(index+1,till_now,houses[index],houses,cost,m,n,target));
            else
                ans = min(ans,solve(index+1,till_now+1,houses[index],houses,cost,m,n,target));   
        }
        dp[index][till_now][prev_paint] = ans;
        return dp[index][till_now][prev_paint];
        //return ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) { 
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,0,houses,cost,m,n,target);
        if( ans >= INT_MAX/2 ) return -1;
        return ans;
        //return solve(0,0,0,houses,cost,m,n,target) > INT_MAX ;
    }
};