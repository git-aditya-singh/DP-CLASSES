#include<bits/stdc++.h>
using namespace std;

//gfg friends pairing======================================================

  //recursive approach
  class Solution
  {
    public:
    int mod=(int)1e9+7;
    int countFriendsPairings(int n) 
    {  if(n<=2)return n;
        return (countFriendsPairings(n-1)+countFriendsPairings(n-2)*(n-1))%mod;
    }
  };

  //memoization
  class Solution
  {
    public:
    int mod=(int)1e9+7;
    
    long long countFriendsPairings(int n,vector<long long>& dp) 
    {  if(n<=2)return dp[n]=n;
       if(dp[n]!=-1)return dp[n];
       if(n<0)return 0;
        return dp[n]=(countFriendsPairings(n-1,dp)+(countFriendsPairings(n-2,dp)*(n-1))%mod)%mod;
    }
    int countFriendsPairings(int n){
        vector<long long>dp(n+1,-1);
         return (int)countFriendsPairings(n,dp);
    }
  };
  
  //tabulation
  class Solution
  {
    public:
    int mod=(int)1e9+7;
    long long countFriendsPairings_(int N,vector<long long>& dp) 
    {  
        for(int n=0;n<=N;n++){
          if(n<=2) {dp[n]= n;continue;}
          dp[n]=(dp[n-1]+(dp[n-2]*(n-1))%mod)%mod;
       }
       return dp[N];
    }
    int countFriendsPairings(int n){
         vector<long long>dp(N+1,-1); 
         return (int)countFriendsPairings_(n,dp);
    }
  };
 
  //space optimization(O(n)->O(1))
  class Solution
  {
    public:
    int mod=(int)1e9+7;
    long long countFriendsPairings_(int N) 
    {   if(N<=2)return N;
        long long a=2,b=1;
        for(int n=3;n<=N;n++){
          long long c=(a+(b*(n-1))%mod)%mod;
          b=a;
          a=c;
       }
       return a;
    }
    int countFriendsPairings(int n){
         return (int)countFriendsPairings_(n);
    }
  };

//divide n numbers in k group

  //recursive approach
  class solution{
      public:
      int divideintoksubsets(int n,int k){
         if(n==k || k==1){return 1;}

         int sepgrp=divideintoksubsets(n-1,k-1);
         int joingrp=divideintoksubsets(n-1,k)*k;
         return sepgrp+joingrp;
      }
  };
  //memoization
  class solution{
      public:
      int divideintoksubsets(int n,int k){
          vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
          return helper(n,k,dp);
      }
      int helper(int n,int k,vector<vector<int>>& dp){
           if(n==k || k==1){
               return dp[n][k]=1;
           }
           if(dp[n][k]!=-1)return dp[n][k];
           int sepgrp=helper(n-1,k-1,dp);
           int joingrp=helper(n-1,k,dp)*k;
           cout<<sepgrp+joingrp<<endl;
           return dp[n][k]=sepgrp+joingrp;
      }
  };

  //tabulation
  class solution{
      public:
      int divideintoksubsets(int n,int k){
          vector<vector<int>>dp(n+1,vector<int>(k+1,0));
          return helper(n,k,dp);
      }
      int helper(int N,int K,vector<vector<int>>& dp){
            for(int k=1;k<=K;k++){
              for(int n=1;n<=N;n++){
               if(n==k || k==1){
                   dp[n][k]=1; continue;
                }
               
               int sepgrp=dp[n-1][k-1];
               int joingrp=dp[n-1][k]*k;
               dp[n][k]=sepgrp+joingrp;
            }
           }
           return dp[N][K];
      }
        
  };

//leetcode 516 longest palindromic subsequence

  //recursive approach
  class Solution {
    public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        return helper(s,0,n-1);
    }
    int helper(string& s,int li,int ri){
        if(li==ri){
            return 1;
        }
        if(li>ri){
            return 0;
        }
        if(s[li]==s[ri]){
            return 2+helper(s,li+1,ri-1);
        }
        return max(helper(s,li+1,ri),helper(s,li,ri-1));
    }
  };

  //memoization
  class Solution {
    public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(s,0,n-1,dp);
    }
    int helper(string& s,int li,int ri,vector<vector<int>>& dp){
        if(li==ri){
            return dp[li][ri]=1;
        }
        if(li>ri){
            return dp[li][ri]=0;
        }
        if(dp[li][ri]!=-1)return dp[li][ri];
        if(s[li]==s[ri]){
            return dp[li][ri]=2+helper(s,li+1,ri-1,dp);
        }
        return dp[li][ri]=max(helper(s,li+1,ri,dp),helper(s,li,ri-1,dp));
    }
  };

  //tabulation
  class Solution {
    public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        return helper(s,0,n-1,dp);
    }
    int helper(string& s,int LI,int RI,vector<vector<int>>& dp){
        int n=s.length();
        for(int gap=0;gap<n;gap++){
        for(int li=0,ri=gap;ri<n;li++,ri++){
            if(li==ri){
            dp[li][ri]=1;continue;
            }
        
        if(s[li]==s[ri]){
           dp[li][ri]=2+dp[li+1][ri-1];continue;
        }
         dp[li][ri]=max(dp[li+1][ri],dp[li][ri-1]);
        }
        }
        return dp[LI][RI];
    }
  };

//leetcode 1143 longest common subsequence
 
  //recursion
  class Solution {
    public:
    int longestCommonSubsequence(string text1, string text2) {        
        return helper(text1,text2,0,0,);
    }
    int helper(string &text1,string &text2,int i,int j){
        if(i>=text1.size()||j>=text2.size()){
            return 0;
        }
        
        if(text1[i]==text2[j]){
            return dp[i][j]= 1+helper(text1,text2,i+1,j+1);
        }else
        {
         return dp[i][j]=max(helper(text1,text2,i,j+1),helper(text1,text2,i+1,j));
        }   
    }
  };

  //memoization
  class Solution {
    public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(text1,text2,0,0,dp);
    }
    int helper(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
        if(i>=text1.size()||j>=text2.size()){
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]= 1+helper(text1,text2,i+1,j+1,dp);
        }else
        {
         return dp[i][j]=max(helper(text1,text2,i,j+1,dp),helper(text1,text2,i+1,j,dp));
        }   
    }
  };

  //tabulation
  class Solution {
    public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(text1,text2,0,0,dp);
    }
    int helper(string &text1,string &text2,int I,int J,vector<vector<int>>&dp){
        int n=text1.size();
        int m=text2.size();
        
        for(int i=n;i>=I;i--)
            for(int j=m;j>=J;j--){
              if(i>=text1.size()||j>=text2.size()){
                 dp[i][j]=0;continue;
              }
        
              if(text1[i]==text2[j]){
                 dp[i][j]= 1+dp[i+1][j+1];
              }else
              {
              dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
              }   
        }
        return dp[I][J];
    }
  };

//leetcode 44 wildcard matching

  //recursion
  class Solution {
    public:
    bool isMatch(string s, string p) {
        p=rem(p);
        return helper(s,p,s.size(),p.size());
    }
    bool helper(string & s,string & p,int n,int m){
     if(n==0||m==0){
         if(n==0&&m==0)return 1;
         if(n == 0 && m==1 &&p[m-1] == '*')
             return 1;
         return 0;
     }
     if(s[n-1]==p[m-1]||p[m-1]=='?'){
        return  dp[n][m]=helper(s,p,n-1,m-1);
     }else if(p[m-1]=='*'){
         return helper(s,p,n-1,m) || helper(s,p,n,m-1);
     }else
     { return 0;
     }  
    }
    string rem(string & str){
        int n=str.size();
        if(str.size()==0)return str;
        int i=1;
        char ch = (char)(str[0]);
        string ans;
        ans += ch;
        while(i<n){
            while(i<n&&ans[ans.size()-1]=='*'&&str[i]=='*')i++;
            if(i<n)
            {
                 ans += (char)(str[i]);
            }   
            i++;
        }
        return ans;  
    }
  };
  
  //memoization
  class Solution {
    public:
    bool isMatch(string s, string p) {
        p=rem(p);
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(s,p,s.size(),p.size(),dp);
    }
    bool helper(string & s,string & p,int n,int m,vector<vector<int>>& dp){
     if(n==0||m==0){
         if(n==0&&m==0)return dp[n][m]=1;
         if(n == 0 && m==1 &&p[m-1] == '*')
             return dp[n][m]=1;
         return dp[n][m]=0;
     }
     if(dp[n][m]!=-1)return dp[n][m];
     if(s[n-1]==p[m-1]||p[m-1]=='?'){
        return  dp[n][m]=helper(s,p,n-1,m-1,dp);
     }else if(p[m-1]=='*'){
         return dp[n][m]=helper(s,p,n-1,m,dp) || helper(s,p,n,m-1,dp);
     }else
     { return dp[n][m]=0;
     }  
    }
    string rem(string & str){
        int n=str.size();
        if(str.size()==0)return str;
        int i=1;
        char ch = (char)(str[0]);
        string ans;
        ans += ch;
        while(i<n){
            while(i<n&&ans[ans.size()-1]=='*'&&str[i]=='*')i++;
            if(i<n)
            {
                 ans += (char)(str[i]);
            }   
            i++;
        }
        return ans;  
    }
  };
  
  //tabulation
  class Solution {
    public:
    bool isMatch(string s, string p) {
        p=rem(p);
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(s,p,s.size(),p.size(),dp);
    }
    bool helper(string& s,string& p,int N,int M,vector<vector<int>>& dp){
       for(int n=0;n<=N;n++)
           for(int m=0;m<=M;m++){
            if(n==0||m==0){
                if(n==0&&m==0){dp[n][m]=1;continue;}
                if(n == 0 && m==1 &&p[m-1] == '*')
                {dp[n][m]=1;continue;}
                else
                {
                 dp[n][m]=0;continue;
                }
            }
            if(s[n-1]==p[m-1]||p[m-1]=='?'){
                dp[n][m]=dp[n-1][m-1];
            }else if(p[m-1]=='*'){
                dp[n][m]=(dp[n-1][m] || dp[n][m-1]);
            }else
            {  dp[n][m]=0;
            }  
        }
        cout<<dp[N][M];
        return dp[N][M];
    } 
    string rem(string& str){
        int n=str.size();
        if(str.size()==0)return str;
        int i=1;
        char ch = (char)(str[0]);
        string ans;
        ans += ch;
        while(i<n){
            while(i<n&&ans[ans.size()-1]=='*'&&str[i]=='*')i++;
            if(i<n)
            {
                 ans += (char)(str[i]);
            }   
            i++;
        }
        return ans;  
    }
  };


//main function===================================================
int main(){

}