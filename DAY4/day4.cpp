#include<bits/stdc++.h>
using namespace std;

//leetcode 115 distinct subsequence

  //memoization
  class Solution {
    public:
    int numDistinct(string s, string t) {
         int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(s,t,n,m,dp);
    }
    int helper(string& s,string& t,int n,int m,vector<vector<int>>& dp){
        if(m==0){
                return dp[n][m]=1;
        }
        if(n<m){
            return dp[n][m]=0;    
        }
        if(dp[n][m]!=-1)return dp[n][m];
        int p=0;
        if(s[n-1]==t[m-1]){
            p+= helper(s,t,n-1,m-1,dp);
        }
        p+= helper(s,t,n-1,m,dp);
        return dp[n][m]=p;
    }
  };
  
  //tabulation
  


//main function============================================================================
int main(){

}