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
  class Solution {
    public:
    int numDistinct(string s, string t) {
         int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(s,t,n,m,dp);
    }
    int helper(string& s,string& t,int N,int M,vector<vector<int>>& dp){
    for(int n=0;n<=N;n++){
        for(int m=0;m<=M;m++){
          if(m==0){
                 dp[n][m]=1;continue;
        }
        if(n<m){
             dp[n][m]=0;  continue;  
        }
        long long  p=0;
        if(s[n-1]==t[m-1]){
            p+= dp[n-1][m-1];
        }
        p+= dp[n-1][m];
         dp[n][m]=p;    
        }
    }
        return dp[N][M];
    }
  }; 


//main function============================================================================
int main(){

}