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




//main=====================================================================
int main(){

}

