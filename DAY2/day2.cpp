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

//gfg goldmine problem==================================================

  //recursive approach
  class Solution{
    public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans=INT_MIN;
        vector<vector<int>>dirs={{0,1},{-1,1},{1,1}};
        for(int i=0;i<n;i++){
            ans=max(ans,helper(i,0,M,dirs));
        }
        return ans;
    }
    int helper(int r,int c,vector<vector<int>>& M,vector<vector<int>>& dirs){
        
        int n=M.size();
        int m=M[0].size();
        if(c==m-1){
            return M[r][c];
        }
        int ans=INT_MIN;
        for(auto dir:dirs){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                ans=max(ans,helper(nr,nc,M,dirs));
            }
        }
        return ans+M[r][c];
    }
  };

  //memoization
  class Solution{
    public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans=INT_MIN;
        vector<vector<int>>dirs={{0,1},{-1,1},{1,1}};
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,helper(i,0,M,dirs,dp));
        }
        return ans;
    }
    int helper(int r,int c,vector<vector<int>>& M,vector<vector<int>>& dirs,vector<vector<int>>& dp){
        
        int n=M.size();
        int m=M[0].size();
        if(c==m-1){
            return dp[r][c]=M[r][c];
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=INT_MIN;
        for(auto dir:dirs){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                ans=max(ans,helper(nr,nc,M,dirs,dp));
            }
        }
        return dp[r][c]=ans+M[r][c];
    }
  };

  //tabulation




//main=====================================================================
int main(){

}

