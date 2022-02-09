#include<bits/stdc++.h>
using namespace std;

//leetcode 115 distinct subsequence
  //recursion
  class Solution {
    public:
    int numDistinct(string s, string t) {
         int n=s.size();
        int m=t.size();
        
        return helper(s,t,n,m);
    }
    int helper(string& s,string& t,int n,int m){
        if(m==0){
                return 1;
        }
        if(n<m){
            return 0;    
        }
        int p=0;
        if(s[n-1]==t[m-1]){
            p+= helper(s,t,n-1,m-1);
        }
        p+= helper(s,t,n-1,m);
        return p;
    }
  };

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


//leetcode 72 edit distance

  //recursion
  class Solution {
    public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return helper(word1,word2,n,m);
    }
    int helper(string word1, string word2, int i,int j){
        if(i==0||j==0)return abs(i-j);
        
        if(word1[i-1]==word2[j-1]){
            return  helper(word1,word2,i-1,j-1);
        }
        return (1+min(helper(word1,word2,i-1,j-1),min(helper(word1,word2,i,j-1),helper(word1,word2,i-1,j))));
    }
  };

  //memoization
  class Solution {
    public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        return helper(word1,word2,n,m,dp);
    }
    int helper(string word1, string word2, int i,int j,vector<vector<int>>& dp){
        if(i==0||j==0)return dp[i][j]= abs(i-j);
        if(dp[i][j]!=0)return dp[i][j];
        if(word1[i-1]==word2[j-1]){
            return dp[i][j]= helper(word1,word2,i-1,j-1,dp);
        }
        return dp[i][j]= (1+min(helper(word1,word2,i-1,j-1,dp),min(helper(word1,word2,i,j-1,dp),helper(word1,word2,i-1,j,dp))));
    }
  };

  //tabulation
  class Solution {
    public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        return helper(word1,word2,n,m,dp);
    }
    int helper(string word1, string word2, int I,int J,vector<vector<int>>& dp){
        for(int i=0;i<=I;i++){
            for(int j=0;j<=J;j++){
        if(i==0||j==0){ dp[i][j]= abs(i-j);continue;}
        
        if(word1[i-1]==word2[j-1]){
             dp[i][j]= dp[i-1][j-1];continue;
        }
         dp[i][j]= (1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])));
        }
    }
        return dp[I][J];
    }
  };

  

//main function============================================================================
int main(){

}