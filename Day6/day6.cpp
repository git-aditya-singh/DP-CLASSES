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

//leetcode 140 word break II

  //recursion
  class Solution {
    public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string asf="";
        vector<string>ans;
        helper(s,s.size(),wordDict,ans,asf);  
        return ans;
    }
    void helper(string& s,int pos,vector<string>& wordDict,vector<string>&ans,string asf){
        if(pos<0){
            ans.push_back(asf.substr(0,asf.size()-1));
        }
        for(int i=pos;i>=0;i--){
            string str=s.substr(i,pos-i+1);
            if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end()){
                asf=str+" "+asf;
                helper(s,i-1,wordDict,ans,asf);
                asf=asf.substr(str.size()+1,asf.size());
            }
        }
    }
  };

  //
  //


//Backengineering print maxgold path

  class Solution{
    public:
    void maxGold(int n, int m, vector<vector<int>> M)
    {  
        vector<vector<int>>dirs={{0,1},{-1,1},{1,1}};
        vector<vector<int>>dp(n,vector<int>(m,-1));
        helper(0,0,M,dirs,dp);
    }
    void helper(int R,int C,vector<vector<int>>& M,vector<vector<int>>& dirs,vector<vector<int>>& dp){
        int n=M.size();
        int m=M[0].size();
        for(int c=m-1;c>=C;c--){
            for(int r=n-1;r>=0;r--){
              if(c==m-1){
                 dp[r][c]=M[r][c];continue;
              }
              int ans=INT_MIN;
              for(auto dir:dirs){
              int nr=r+dir[0];
              int nc=c+dir[1];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                  ans=max(ans,dp[nr][nc]);
                }
              }
              dp[r][c]=ans+M[r][c];
            }
        }
        int maxgold = 0;
        int idx=-1;
        for(int i = 0; i<n; i++)
        { 
            if(dp[i][0]>maxgold){
                maxgold=dp[i][0];
                idx=i;
            }
        }
        cout<<idx<<endl;
        string asf="";
        if(idx!=-1){
        goldpath_backengg(idx,0,dp,asf,dirs);
        }
        
    }
    void goldpath_backengg(int r,int c,vector<vector<int>>& dp,string asf,vector<vector<int>>&dirs){
        if(c==dp[0].size()-1){
            asf+="("+to_string(r) + "," + to_string(c) + ")";
            cout<<asf;return;
        }
        int maxgold=0;
        int t=-1;  
        for(int d=0;d<dirs.size();d++){
            int nr=r+dirs[d][0];
            int nc=c+dirs[d][1];
            if(nr<dp.size()&&nr>=0&&nc<dp[0].size()&&nc>=0&&dp[nr][nc]>maxgold){
                maxgold=dp[nr][nc];
                t=d;
            }
        }
        if(t!=-1){
            asf+="("+to_string(r) + "," + to_string(c) + ")";
            goldpath_backengg(r+dirs[t][0],c+dirs[t][1],dp,asf,dirs);
        }

    }
  };

//leetcode 300 longest increasing subsequence

  //memoization
  class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(-1,0,nums,dp);
    }
    int helper(int prev,int idx,vector<int>& nums,vector<vector<int>>& dp){
        if(idx==nums.size()){
            return 0;
        }
        if( prev !=-1 && dp[prev][idx]!=-1)return dp[prev][idx];
        int p1=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            p1=1+helper(idx,idx+1,nums,dp);
        }
        int p2=helper(prev,idx+1,nums,dp);
        if(prev!=-1){
            dp[prev][idx]=max(p1,p2);
        }
        return max(p1,p2);
    }
  };
  


//main function===================================================================
int main(){
    
}