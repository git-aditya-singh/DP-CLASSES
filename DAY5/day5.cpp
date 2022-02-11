#include<bits/stdc++.h>
using namespace std;

//leetcode 1035 uncrossed lines

  //recursive approach
  class Solution {
    public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums 1,nums2,0,0,dp);
    }
    int helper(vector<int>& nums1, vector<int>& nums2,int idx1,int idx2){
        if(idx1==nums1.size()||idx2==nums2.size()){
            return 0;
        }
        
        if(nums1[idx1]==nums2[idx2]){
            return 1+helper(nums1,nums2,idx1+1,idx2+1);
        }
        return max(helper(nums1,nums2,idx1+1,idx2),helper(nums1,nums2,idx1,idx2+1));
    }
  };

  //memoization
  class Solution {
    public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return helper(nums 1,nums2,0,0,dp);
    }
    int helper(vector<int>& nums1, vector<int>& nums2,int idx1,int idx2,vector<vector<int>>& dp){
        if(idx1==nums1.size()||idx2==nums2.size()){
            return dp[idx1][idx2]=0;
        }
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(nums1[idx1]==nums2[idx2]){
            return dp[idx1][idx2]=1+helper(nums1,nums2,idx1+1,idx2+1,dp);
        }
        return dp[idx1][idx2]=max(helper(nums1,nums2,idx1+1,idx2,dp),helper(nums1,nums2,idx1,idx2+1,dp));
    }
  };

  //tabulation
  class Solution {
    public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return helper(nums1,nums2,0,0,dp);
    }
    int helper(vector<int>& nums1, vector<int>& nums2,int IDX1,int IDX2,vector<vector<int>>& dp){
        for(int idx1=nums1.size();idx1>=IDX1;idx1--)
            for(int idx2=nums2.size();idx2>=IDX2;idx2--){
        if(idx1==nums1.size()||idx2==nums2.size()){
             dp[idx1][idx2]=0; continue;
        }
        if(nums1[idx1]==nums2[idx2]){
            dp[idx1][idx2]=1+dp[idx1+1][idx2+1];continue;
        }
        dp[idx1][idx2]=max(dp[idx1+1][idx2],dp[idx1][idx2+1]);
    }
        return dp[IDX1][IDX2];
    }
    
  };

//leetcode 1458 Max Dot Product of Two Subsequences

  //recursive approach
  class Solution {
    public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return helper(nums1,nums2,0,0);
    }
    int helper(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i==nums1.size()||j==nums2.size()){
            return -1e8;
        }
        int currm=nums1[i]*nums2[j]+helper(nums1,nums2,i+1,j+1);
        int n2p=helper(nums1,nums2,i,j+1);
        int n1p=helper(nums1,nums2,i+1,j);
        return max(max(currm,nums1[i]*nums2[j]),max(n2p,n1p));
    }
  };

  //memoization
  class Solution {
    public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1e9));
        return helper(nums1,nums2,0,0,dp);
    }
    int helper(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>>& dp){
        if(i==nums1.size()||j==nums2.size()){
            return dp[i][j]=-1e8;
        }
        if(dp[i][j]!=-1e9)return dp[i][j];
        int currm=nums1[i]*nums2[j]+helper(nums1,nums2,i+1,j+1,dp);
        int n2p=helper(nums1,nums2,i,j+1,dp);
        int n1p=helper(nums1,nums2,i+1,j,dp);
        return dp[i][j]=max(max(currm,nums1[i]*nums2[j]),max(n2p,n1p));
    }
  };

  //tabulation
  class Solution {
    public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1e9));
        return helper(nums1,nums2,0,0,dp);
    }
    int helper(vector<int>& nums1, vector<int>& nums2,int I,int J,vector<vector<int>>& dp){
        for(int i=nums1.size();i>=I;i--)
            for(int j=nums2.size();j>=J;j--){
           if(i==nums1.size()||j==nums2.size()){
                dp[i][j]=-1e8;continue;
           }
           int currm=nums1[i]*nums2[j]+dp[i+1][j+1];
           int n2p=dp[i][j+1];
           int n1p=dp[i+1][j];
            dp[i][j]=max(max(currm,nums1[i]*nums2[j]),max(n2p,n1p));
        }
        return dp[I][J];
    }
  };

//============================================================================================================
//================================================SIMILAR QUESTIONS===========================================
//============================================================================================================

//leetcode 647 total number of palindromic substring

  //tabulation (because recursion seems jugaad to me in this question)
  class Solution {
    public:
    int PalindromicStrings(string s) {
        int n=s.size();
        int count=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){dp[i][j]=true;}
                else
                if(gap==1){
                    if(s[i]==s[j]){dp[i][j]=true;}
                }else
                if(s[i]==s[j]&&dp[i+1][j-1]){dp[i][j]=true;}
                if(dp[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
  };

//maximum length of palindromic substring

  //tabulation
  class Solution {
    public:
    int MaxLengthPalindrome(string s) {
        int n=s.size();
        int maxlen=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){dp[i][j]=true;}
                else
                if(gap==1){
                    if(s[i]==s[j]){dp[i][j]=true;}
                }else
                if(s[i]==s[j]&&dp[i+1][j-1]){dp[i][j]=true;}
                if(dp[i][j]&& j-i+1>maxlen){
                    maxlen=j-i+1;
                }
            }
        }
        return maxlen;
    }
  };

//leetcode 5 longest palindromic substring

  //tabulation
  class Solution {
    public:
    string longestPalindrome(string s) {
       int n=s.size();
        int maxlen=0;int si=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){dp[i][j]=true;}
                else
                if(gap==1){
                    if(s[i]==s[j]){dp[i][j]=true;}
                }else
                if(s[i]==s[j]&&dp[i+1][j-1]){dp[i][j]=true;}
                if(dp[i][j]&&j-i+1>maxlen){
                    maxlen=j-i+1;si=i;
                }
            }
        }
        return s.substr(si,maxlen);
    }
  };

//print all palindromic substring

  //tabulation
  class Solution {
    public:
    void longestPalindrome(string s) {
       int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){dp[i][j]=true;}
                else
                if(gap==1){
                    if(s[i]==s[j]){dp[i][j]=true;}
                }else
                if(s[i]==s[j]&&dp[i+1][j-1]){dp[i][j]=true;}
                if(dp[i][j]){
                 cout<<s.substr(i,j-i+1)<<endl;            
                }
            }
        }
    }
  };

//GFG longest common substring

  //tabulation
  class Solution{
    public: 
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        return helper(S1,S2,dp);
    }
    int helper(string &text1,string &text2,vector<vector<int>>&dp){
        int n=text1.size();
        int m=text2.size();
        int maxlen=1;        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
              if(i==0||j==0){
                 dp[i][j]=0;continue;
              }
              if(text1[i-1]==text2[j-1]){
                 dp[i][j]= 1+dp[i-1][j-1];
                 maxlen=max(maxlen,dp[i][j]);
              }   
        }
        return maxlen;
    }
  };

//============================================================================================================
//==============================================SIMILAR QUESTIONS ENDS========================================
//============================================================================================================

//leetcode 583 Delete Operation for Two Strings(application of longest common subsequence)
  
  //recursive approach
  class Solution {
    public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return  n+m-2*helper(word1,word2,0,0);
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
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return  n+m-2*helper(word1,word2,0,0,dp);
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
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return  n+m-2*helper(word1,word2,0,0,dp);
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

//leetcode 132 palindromic partitioning II

  //testcase => fafaaaabaaageeg (why not making cut on longest palindrome because it is possible cut on smaller palindrome will give us minimum result).
  
  //recursive approach
  class Solution {
    public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>pd(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){pd[i][j]=true;}
                else
                if(gap==1){
                    if(s[i]==s[j]){pd[i][j]=true;}
                }else
                if(s[i]==s[j]&&pd[i+1][j-1]){pd[i][j]=true;}
            }
        } 
        return helper(pd,s,0,n-1);
    }
    int helper(vector<vector<bool>>&pd,string& s,int si,int ei){
        if(pd[si][ei])return 0;
        int ans=1e8;
        for(int cut=si;cut<ei;cut++){
            if(pd[si][cut]){
                ans=min(ans,helper(pd,s,cut+1,ei,dp));
            }
        }
        return ans+1;  
    }
  };

  //memoization
  class Solution {
    public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>pd(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){pd[i][j]=true;}
                else
                if(gap==1){
                    if(s[i]==s[j]){pd[i][j]=true;}
                }else
                if(s[i]==s[j]&&pd[i+1][j-1]){pd[i][j]=true;}
            }
        } 
        vector<int>dp(n+1,-1);
        return helper(pd,s,0,n-1,dp);
    }
    int helper(vector<vector<bool>>&pd,string& s,int si,int ei,vector<int>& dp){
        if(pd[si][ei])return 0;
        if(dp[si]!=-1)return dp[si];
        int ans=1e8;
        for(int cut=si;cut<ei;cut++){
            if(pd[si][cut]){
                ans=min(ans,helper(pd,s,cut+1,ei,dp));
            }
        }
        return dp[si]=ans+1;   
    }
  };

  //tabulation
  class Solution {
    public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>>pd(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){pd[i][j]=true;}
                else
                if(gap==1){
                    if(s[i]==s[j]){pd[i][j]=true;}
                }else
                if(s[i]==s[j]&&pd[i+1][j-1]){pd[i][j]=true;}
            }
        } 
        vector<int>dp(n+1,-1);
        return helper(pd,s,0,n-1,dp);
    }
    int helper(vector<vector<bool>>&pd,string& s,int SI,int EI,vector<int>& dp){
        for(int si=EI,ei=EI;si>=SI;si--){
        if(pd[si][ei]){dp[si]=0;continue;}
        int ans=1e8;
        for(int cut=si;cut<ei;cut++){
            if(pd[si][cut]){
                ans=min(ans,dp[cut+1]);
            }
        }
         dp[si]=ans+1;  
        }
        return dp[SI];
    }
    
  };
  /*
  preprocessing for palindrome reduces the time complexity alott to find out minimum cut in the above problem.
  */

 
//gfg Count subsequences of type a^i, b^j, c^k

     /*      ===========================================Theory==================================================
     Every time we get new character we have two options.
     1.it will not join our answer
     2.it will join our answer

     In condition 1 if it does not join the count of subsequence of that character remains same.
     In condition 2 if it joins again it have 2 options one to join its preceeding group or join its own group.
            =>for eg 
            emptycount         =1
            Acount(a^i)        =0
            Bcount(a^i+b^j)    =0
            Ccount(a^i+b^j+c^k)=0
        
        if we get a character C if it does not join our answer will remain same.
        but if it decide to join either it can join the group of Bcount or in its own group Ccount.
        
        same for A also when we get A either it would not join then Acount will remain same 
        and if it join it have again 2 option
        either to join emptycount or its own group Acount

        same for B also when we get A either it would not join then Acount will remain same 
        and if it join it have again 2 option
        either to join Acount or its own group Bcount    
     
        with this observation we have derived the formula used below to calculate Acount,Bcount,Ccount respectively.
     */

   //tabulation
   #define ll long long
   class Solution{
    public:
    int fun(string &s) {
        ll mod= 1e9+7,empcnt=1,acnt=0,bcnt=0,ccnt=0;
        int n=s.size();
        for(char& ch:s){
            if(ch=='a'){
                acnt=((2*acnt)%mod+empcnt)%mod;
            }else
            if(ch=='b'){
                bcnt=((2*bcnt)%mod+acnt)%mod;
            }else
            if(ch=='c'){
                ccnt=((2*ccnt)%mod+bcnt)%mod;
            }
        }
        return (int)(ccnt%mod);
    }
  };


//main function============================================================================
int main(){

}