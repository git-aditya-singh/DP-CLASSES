class Solution {
    public static int mod=(int)1e9+7;
    public int numDecodings(String s) {
        long[] dp=new long[s.length()+1];
        Arrays.fill(dp,-1);
        return (int)helper(s,0,dp);
    }
    public long helper(String s,int idx,long[] dp){
        if(idx==s.length()){
            return dp[idx]=1;
        }
        if(dp[idx]!=-1)return dp[idx];
        char ch=s.charAt(idx);
        if(ch=='0'){
            return dp[idx]=0;
        }
        long count=0;
        if(ch=='*'){
            count=(count+9*helper(s,idx+1,dp))%mod;
            if(idx<s.length()-1){
                char ch2=s.charAt(idx+1);
                if(ch2>='0'&&ch2<='6'){
                    count=(count+2*helper(s,idx+2,dp))%mod;
                }else
                if(ch2>='7'&&ch2<='9'){
                    count=(count+helper(s,idx+2,dp))%mod;
                }else
                {
                    count=(count+15*helper(s,idx+2,dp))%mod;
                }
            }
        }else
        {  count=(count+helper(s,idx+1,dp))%mod;
           if(idx<s.length()-1){
            char ch2=s.charAt(idx+1);
              if(ch2=='*'&&ch=='1'){
                  count=(count+9*helper(s,idx+2,dp))%mod;
              }else
              if(ch2=='*'&&ch=='2'){
                  count=(count+6*helper(s,idx+2,dp))%mod;
              }else if(ch2!='*')
              {
                  int val=(ch-'0')*10+(ch2-'0');
                  if(val<=26){
                      count=(count+helper(s,idx+2,dp))%mod;
                  }
              }
           }
        }
        return dp[idx]=count;
    }
    
}