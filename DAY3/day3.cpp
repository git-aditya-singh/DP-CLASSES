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


//main function===================================================
int main(){

}