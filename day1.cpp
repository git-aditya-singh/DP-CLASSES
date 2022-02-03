#include<bits/stdc++.h>
using namespace std;

//leetcode 509 fibonacci number
  
  //recursive approach
  class Solution {
    public:
    int fib(int n) {
        if(n<=1)return n;
       return fib(n-1)+fib(n-2);
    }
  };

  //memoization
  class Solution {
    public:
    int fib(int n,vector<int>&dp) {
        if(n<=1)return n;
        if(dp[n]!=0){
            return dp[n];
        }
        dp[n]= fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
        
    }
    int fib(int n) {
        vector<int>dp(n+1,0);
        return fib(n,dp);
    }
  };

  //tabulation
  class Solution {
    public:
    int fib(int N) {
        vector<int>dp(N+1,0);
        for(int n=0;n<=N;n++){
        if(n<=1){dp[n]=n;continue;}
        
        dp[n]= dp[n-1]+dp[n-2];
        }
        return dp[N];
    }
  };


//leetcode 62 unique path

  //memoization
  class Solution {
    public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dirs={{1,0},{0,1}};
        vector<vector<int>>dp(m,vector<int>(n,0));
        return helper(0,0,m-1,n-1,dirs,dp);
        
    }
    int helper(int sr,int sc,int dr,int dc,vector<vector<int>>dirs,vector<vector<int>>&dp){
        if(sr==dr&&sc==dc){
            return 1;
        }
        if(dp[sr][sc]!=0)return dp[sr][sc];
        int count=0;
        for(auto dir:dirs){
            int r=sr+dir[0];
            int c=sc+dir[1];
            if(r<=dr&&c<=dc){
                count+=helper(r,c,dr,dc,dirs,dp);
            }
            
        }
        
        return dp[sr][sc]=count;
        
    }
  }; 

  //tabulation
  class Solution {
    public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dirs={{1,0},{0,1}};
        vector<vector<int>>dp(m,vector<int>(n,0));
        return helper(m,n,dirs,dp);
        
    }
    int helper(int m,int n,vector<vector<int>>dirs,vector<vector<int>>dp){
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
            if(i==m-1&&j==n-1)
            {dp[i][j]=1;}
            
            for(auto dir:dirs){
                  int r=i+dir[0];
                  int c=j+dir[1];
                  if(r>=0&&c>=0 &&  r < dp.size() && c < dp[0].size()){
                     dp[i][j]+=dp[r][c];
                   }
                } 
            }
        }
        return dp[0][0];    
    }
  };  

//leetcode 63 unique path II

  //memoization
  class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n=obs.size();
        int m=obs[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        vector<vector<int>>dirs={{1,0},{0,1}};
        return memo_helper(0,0,n-1,m-1,obs,dp,dirs);
        
    }
    int memo_helper(int sr,int sc,int dr,int dc,vector<vector<int>>& grid,vector<vector<int>>& dp,vector<vector<int>>& dirs){
        if(grid[sr][sc]==1)return 0;
        if(sr==dr&&sc==dc){
            dp[sr][sc]=1;return 1;
        }
        if(dp[sr][sc]!=0)return dp[sr][sc];
        
        
        int step=0;
        for(auto dir:dirs){
         int r=sr+dir[0];
         int c=sc+dir[1];
         if(r<dp.size()&&c<dp[0].size()){
             step+=memo_helper(r,c,dr,dc,grid,dp,dirs);
         }
        }        
        return dp[sr][sc]=step;
    }
  };

  //tabulation
  class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n=obs.size();
        int m=obs[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        vector<vector<int>>dirs={{1,0},{0,1}};
        return helper(0,0,n-1,m-1,obs,dp,dirs);
    }
    
    int helper(int SR,int SC,int DR,int DC,vector<vector<int>>& grid,vector<vector<int>>& dp,vector<vector<int>>& dirs){
        for(int sr=DR;sr>=0;sr--){
            for(int sc=DC;sc>=0;sc--){
                if(grid[sr][sc]==1)continue;
        if(sr==DR&&sc==DC){
            dp[sr][sc]=1;continue;
        }
        long step=0;
        for(auto dir:dirs){
         int r=sr+dir[0];
         int c=sc+dir[1];
         if(r<dp.size()&&c<dp[0].size()){
             step+=dp[r][c];
         }
        }        
          dp[sr][sc]=step;
            }
        }
        return dp[SR][SC];
    }
  };

//leetcode 70 Climbing stairs

  //memoization
  class Solution {
    public:
    int climbStairs(int n) {
        vector<int>dp(n,0);
        int s0=helper(0,n,dp);
        return s0;
    }
    int helper(int idx,int n,vector<int>&dp){
        if(idx==n)return 1;
        if(idx>n)return 0;
        if(dp[idx]!=0)return dp[idx];
        int s1=helper(idx+1,n,dp);
        int s2=helper(idx+2,n,dp);
        
        return dp[idx]=s1+s2;
    }
  };

  //tabulation
  class Solution {
    public:
    int climbStairs(int n) {
        vector<int>dp(n,0);
        int s0=helper(n,dp);
        return s0;
    }
    int helper(int n,vector<int>&dp){
        for(int idx=n-1;idx>=0;idx--){
            if(idx==n-1){dp[idx]=1;continue;}
            if(idx==n-2){dp[idx]=2;continue;}
            dp[idx]=dp[idx+1]+dp[idx+2];            
        }
        return dp[0];
    }
  };

//leetcode 746 Min cost climbing stairs 

  //memoization
  class Solution {
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int idx=-1;
        return min(helper(idx+1,cost,dp),helper(idx+2,cost,dp));
        
    }
    int helper(int idx,vector<int>& cost,vector<int>& dp){
        
        if(idx==cost.size()-1)
          return cost[cost.size()-1];
        if(idx>=cost.size()){
            return 0;
        }  
        if(dp[idx]!=-1)return dp[idx];
        return dp[idx]=cost[idx]+min(helper(idx+1,cost,dp),helper(idx+2,cost,dp));
    }
  };

  //tabulation
  class Solution {
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int idx=-1;
        return min(helper_tab(idx+1,cost,dp),helper_tab(idx+2,cost,dp));
        
    }
    int helper_tab(int IDX,vector<int>&cost,vector<int>& dp){
        for(int idx=cost.size()-1;idx>=IDX;idx--){
            if(idx==cost.size()-1)
            {dp[idx]=cost[idx];continue;}
           if(idx+2<=cost.size()-1) 
               dp[idx]=cost[idx]+min(dp[idx+1],dp[idx+2]);
            else
            {
                dp[idx]=cost[idx];
            }
        }
        return dp[IDX];  
    }
};

//main function========================================================
int main(){
    
    
    
    
    return 0;
}

