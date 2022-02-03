#include<bits/stdc++.h>
using namespace std;

//leetcode 91 decode ways

  //memoization
  class Solution {
    public:
    int helper(int idx,string s,vector<int>& dp){
        if(idx==s.size()){
            return dp[idx]=1;
        }
        char ch=s[idx];
        if(ch=='0'){
            return dp[idx]=0;
        }
        if(dp[idx]!=-1)return dp[idx];
        
        int count=helper(idx+1,s,dp);
        if(idx<s.size()-1){
            char ch2=s[idx+1];
            int val=(ch-'0')*10+(ch2-'0');
            if(val<=26){
                count+=helper(idx+2,s,dp);
            }
        }
        return dp[idx]=count;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return helper(0,s,dp);
    }
  };

  //tabulation
  class Solution {
    public:
    int helper(int IDX,string s,vector<int>& dp){
        for(int idx=s.size();idx>=IDX;idx--){
            if(idx==s.size()){
            dp[idx]=1;continue;
        }
        char ch=s[idx];
        if(ch=='0'){
             dp[idx]=0;continue;
        }
        
        int count=dp[idx+1];
        if(idx<s.size()-1){
            char ch2=s[idx+1];
            int val=(ch-'0')*10+(ch2-'0');
            if(val<=26){
                count+=dp[idx+2];
            }
        }
            dp[idx]=count;
        }
        return dp[IDX];
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return helper(0,s,dp);
    }
  };

  //optimization (space O(n)->O(1))
  class Solution {
    public:
    int helper(int IDX,string s){
        int a=1,b=0;
        for(int idx=s.size();idx>=IDX;idx--){
        char ch=s[idx];
        int sum=0;
        if(ch!='0'){
          sum+=a;
        if(idx<s.size()-1){
            char ch2=s[idx+1];
            int val=(ch-'0')*10+(ch2-'0');
            if(val<=26){
                sum+=b;
            }
        }   
        }
            b=a;
            a=sum;
        }
        return a;
    }
    int numDecodings(string s) {
        int n=s.length();
        return helper(0,s);
    }
  };

  





//main=====================================================================
int main(){

}

