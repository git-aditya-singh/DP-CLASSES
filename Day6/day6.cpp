#include<bits/stdc++.h>
using namespace std;

//leetcode 139 word break=========================================================

  //recursive approach
  class Solution {
    public:  
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(s,0,wordDict);   
    }
    bool helper(string& s,int pos, vector<string>& wordDict){
        if(pos==s.size())return true;
        for(int i=pos;i<s.size();i++){
            string str=s.substr(pos,i-pos+1);
            if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end()&&helper(s,i+1,wordDict)){
                return true;
            }
        }
        return false;
    }
  };

  //memoization
  class Solution {
    public:  
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return helper(s,0,wordDict,dp);   
    }
    bool helper(string& s,int pos, vector<string>& wordDict,vector<int>& dp){
        if(pos==s.size())return true;
        if(dp[pos]!=-1)return dp[pos];
        for(int i=pos;i<s.size();i++){
            string str=s.substr(pos,i-pos+1);
            if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end()&&helper(s,i+1,wordDict,dp)){
                dp[pos]=1;
                return true;
            }
        }
        dp[pos]=0;
        return false;
    }
  };

  //tabulation

// longest palindromic subsequence reverse engg printing longest palindromic subsequence

  //recursion
  class solution{
      public:
      string lpssbackengg(int si,int ei,string s,vector<vector<int>>& dp){
          if(si>=ei){
              if(si==ei){
                  return to_string(s[si]);
              }
              return "";
          }
          if(s[si]==s[ei])
          {
              return s[si]+lpssbackengg(si+1,ei-1,s,dp)+s[ei];
          }
          if(dp[si+1][ei]>dp[si][ei-1]){
              return lpssbackengg(si+1,ei,s,dp);
          }
          return lpssbackengg(si,ei-1,s,dp);
      }
      string lpssprint(string s){
          int n=s.size();
          vector<vector<int>>dp(n,vector<int>(n,0));
          for(int gap=0;gap<n;gap++){
              for(int i=0,j=gap;j<n;j++,i++){
                  if(gap==0){
                      dp[i][j]=1;continue;
                  }
                  if(gap==1){
                      if(s[i]==s[j]){
                          dp[i][j]=2;continue;
                      }
                  }
                  dp[i][j]=max(dp[i+1][j],dp[i][j -1]);
              }
          }
          return lpssbackengg(0,n-1,s,dp);
      }
  };



//main function===================================================================
int main(){
    
}