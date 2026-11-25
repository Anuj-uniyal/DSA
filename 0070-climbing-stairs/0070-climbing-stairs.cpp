class Solution {
public:
   int idk(int i,int n,vector<int>&dp){
    if(i==n)return 1;
    if(i>n)return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
   int a=idk(i+1,n,dp);
   int b=idk(i+2,n,dp);
   dp[i]=a+b;
   return dp[i];
   }
    int climbStairs(int n){
        vector<int>dp(n+1,-1);
        if(n<=1)return 1;
        return idk(0,n,dp);
    }
};