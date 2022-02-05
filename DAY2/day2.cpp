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

//decode ways II

  //memoization
  class Solution {
    public:
    int mod=(int)(1e9+7);
    int numDecodings(string s) {
        int n=s.size();
        vector<long long>dp(n+1,-1);
        return (int)(helper(s,0,dp));
    }
    long long helper(string & s,int idx,vector<long long>& dp){
        if(idx==s.length()){
            return dp[idx]=1;
        }
        if(dp[idx]!=-1)return dp[idx];
        char ch=s[idx];
        if(ch=='0'){
            return dp[idx]=0;
        }
        long long count=0;
        if(ch=='*'){
            count=(count+9*helper(s,idx+1,dp))%mod;
            if(idx<s.size()-1){
                char ch1=s[idx+1];
                if(ch1>='0'&&ch1<='6'){
                    count=(count+2*helper(s,idx+2,dp))%mod;
                }else{
                    if(ch1>='7'&&ch1<='9'){
                        count=(count+helper(s,idx+2,dp))%mod;
                    }else
                    {
                        count=(count+15*helper(s,idx+2,dp))%mod;   
                    }
                }
            }
        }else
        {
            count =(count+helper(s,idx+1,dp))%mod;
            if(idx<s.size()-1){
                char ch1=s[idx+1];
                if(ch=='1'&&ch1=='*'){
                    count=(count+9*helper(s,idx+2,dp))%mod;
                }else
                if(ch=='2'&&ch1=='*'){
                    count=(count+6*helper(s,idx+2,dp))%mod;
                }
                else if(ch1!='*'){
                    int val=(ch-'0')*10+ch1-'0';
                    if(val<=26){
                        count=(count+helper(s,idx+2,dp))%mod;
                    }
                }
            }
        }
        return dp[idx]=count;
        
    }
  };

  //tabulation
  class Solution {
    public:
    int mod=(int)(1e9+7);
    int numDecodings(string s) {
        int n=s.size();
        vector<long long>dp(n+1,-1);
        return (int)(helper(s,0,dp));
    }
    long long helper(string & s,int IDX,vector<long long>& dp){
        for(int idx=s.length();idx>=IDX;idx--){
        if(idx==s.length()){
             dp[idx]=1;continue;
        }
        char ch=s[idx];
        if(ch=='0'){
             dp[idx]=0;continue;
        }
        long long count=0;
        if(ch=='*'){
            count=(count+9*dp[idx+1])%mod;
            if(idx<s.size()-1){
                char ch1=s[idx+1];
                if(ch1>='0'&&ch1<='6'){
                    count=(count+2*dp[idx+2])%mod;
                }else{
                    if(ch1>='7'&&ch1<='9'){
                        count=(count+dp[idx+2])%mod;
                    }else
                    {
                        count=(count+15*dp[idx+2])%mod;   
                    }
                }
            }
        }else
        {
            count =(count+dp[idx+1])%mod;
            if(idx<s.size()-1){
                char ch1=s[idx+1];
                if(ch=='1'&&ch1=='*'){
                    count=(count+9*dp[idx+2])%mod;
                }else
                if(ch=='2'&&ch1=='*'){
                    count=(count+6*dp[idx+2])%mod;
                }
                else if(ch1!='*'){
                    int val=(ch-'0')*10+ch1-'0';
                    if(val<=26){
                        count=(count+dp[idx+2])%mod;
                    }
                }
            }
        }
          dp[idx]=count;
        }
        return dp[IDX];
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
  class Solution{
    public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {  
        vector<vector<int>>dirs={{0,1},{-1,1},{1,1}};
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = helper(0,0,M,dirs,dp);
        return ans;
    }
    int helper(int R,int C,vector<vector<int>>& M,vector<vector<int>>& dirs,vector<vector<int>>& dp){
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
        int mm = -1;
        for(int i = 0; i<n; i++)
        {
         mm = max(mm, dp[i][0]); 
        }
        return mm;
    }
  };

//maximum path sum in matrix

  //recursive approach
  class Solution{
    public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n=Matrix.size();
        int m=Matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dirs={{1,0},{1,1},{1,-1}};
        for(int i=0;i<m;i++){
            ans=max(ans,helper(0,i,Matrix,dirs));
        }
        return ans;
    }
    int helper(int r,int c,vector<vector<int>>& Matrix,vector<vector<int>>& dirs){
        if(r==Matrix.size()-1){
            return Matrix[r][c];
        }
        int ans=INT_MIN;
        for(auto dir:dirs){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr<Matrix.size()&&nc>=0&&nc<Matrix[0].size()){
                ans=max(ans,helper(nr,nc,Matrix,dirs));
            }
        }
        return ans+Matrix[r][c];
    }
  };

  //memoization
  class Solution{
    public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n=Matrix.size();
        int m=Matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<vector<int>>dirs={{1,0},{1,1},{1,-1}};
        for(int i=0;i<m;i++){
            ans=max(ans,helper(0,i,Matrix,dirs,dp));
        }
        return ans;
    }
    int helper(int r,int c,vector<vector<int>>& Matrix,vector<vector<int>>& dirs,vector<vector<int>>& dp){
        if(r==Matrix.size()-1){
            return Matrix[r][c];
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=INT_MIN;
        for(auto dir:dirs){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr<Matrix.size()&&nc>=0&&nc<Matrix[0].size()){
                ans=max(ans,helper(nr,nc,Matrix,dirs,dp));
            }
        }
        return dp[r][c]=ans+Matrix[r][c];
    }
  };

  //tabulation
  class Solution{
    public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n=Matrix.size();
        int m=Matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<vector<int>>dirs={{1,0},{1,1},{1,-1}};
        return helper(Matrix,dirs,dp);
        
    }
    int helper(vector<vector<int>>& Matrix,vector<vector<int>>& dirs,vector<vector<int>>& dp){
        for(int r=Matrix.size()-1;r>=0;r--){
          for(int c=Matrix[0].size()-1;c>=0;c--){    
            if(r==Matrix.size()-1){
                dp[r][c]= Matrix[r][c];continue;
            }
            int ans=INT_MIN;
            for(auto dir:dirs){
               int nr=r+dir[0];
               int nc=c+dir[1];
               if(nr<Matrix.size()&&nc>=0&&nc<Matrix[0].size()){
                ans=max(ans,dp[nr][nc]);
               }
            }
         dp[r][c]=ans+Matrix[r][c];
       }
      }
      int ans=INT_MIN;
      for(int i=0;i<Matrix[0].size();i++){
            ans=max(ans,dp[0][i]);
        }
        return ans;
    }
  };

//leetcode 64 minimum path sum

  //recursive approach
  class Solution {
    public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dirs={{0,1},{1,0}};
        return helper(0,0,grid,dirs);     
    }
    int helper(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dirs){
        if(r==grid.size()-1 && c==grid[0].size()-1){
            return grid[r][c];
        }
        int ans=INT_MAX;
        for(auto& dir:dirs){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr<grid.size()&&nc<grid[0].size()){
                ans=min(ans,helper(nr,nc,grid,dirs));
            }
        }
        return grid[r][c]+ans;
    }
  };   

  //memoization
  class Solution {
    public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dirs={{0,1},{1,0}};
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(0,0,grid,dirs,dp);     
    }
    int helper(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dirs,vector<vector<int>>& dp){
        if(r==grid.size()-1 && c==grid[0].size()-1){
            return grid[r][c];
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=INT_MAX;
        for(auto& dir:dirs){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr<grid.size()&&nc<grid[0].size()){
                ans=min(ans,helper(nr,nc,grid,dirs,dp));
            }
        }
        return dp[r][c]=grid[r][c]+ans;
    }
  };

  //tabulation
  class Solution {
    public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dirs={{0,1},{1,0}};
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(0,0,grid,dirs,dp);     
    }
    int helper(int R,int C,vector<vector<int>>& grid,vector<vector<int>>& dirs,vector<vector<int>>& dp){
        for(int r=grid.size()-1;r>=R;r--)
        for(int c=grid[0].size()-1;c>=C;c--){    
        if(r==grid.size()-1 && c==grid[0].size()-1){
            dp[r][c]=grid[r][c];continue;
        }
        
        int ans=INT_MAX;
        for(auto& dir:dirs){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr<grid.size()&&nc<grid[0].size()){
                ans=min(ans,dp[nr][nc]);
            }
        }
           dp[r][c]=grid[r][c]+ans;
        }
        return dp[R][C];
    }
  };  



//main=====================================================================
int main(){

}

