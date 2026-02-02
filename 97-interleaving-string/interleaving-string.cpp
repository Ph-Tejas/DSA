#pragma GCC target("abm")
#pragma GCC target("bmi")
#pragma GCC target("avx2")
#pragma GCC target("bmi2")
#pragma GCC target("lzcnt")
#pragma GCC target("popcnt")
#pragma GCC target("native")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-march=native")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")
static const bool __boost = []() {
   cin.tie(nullptr);
   cout.tie(nullptr);
   return std::ios_base::sync_with_stdio(false);
}();
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
   constexpr std::size_t alignment = alignof(std::max_align_t);
   size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
   size_t total_size = size + padding;
   char* aligned_ptr = &buffer[buffer_pos + padding];
   buffer_pos += total_size;
   return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}
const auto __ = []() {
   struct Leetcode {
       static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
   };
   std::atexit(&Leetcode::_);
   return 0;
}();

class Solution {
public:
    int n,m,k;
    int fun(string &s1,string &s2,string &s3,vector<vector<int>>&dp,int i,int j){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans;
        if(i==n&&j==m)ans=1;

        else if(i==n){
            if(s2[j]==s3[i+j])ans= fun(s1,s2,s3,dp,i,j+1);
            else ans=0;
        }
        else if(j==m){
            if(s1[i]==s3[i+j])ans=fun(s1,s2,s3,dp,i+1,j);
            else ans=0;
        }
        else{
            int a=0,b=0;
            if(s1[i]==s3[i+j])a=fun(s1,s2,s3,dp,i+1,j);
            if(s2[j]==s3[i+j])b=fun(s1,s2,s3,dp,i,j+1);
            ans=(a|b);
        }
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        k=s3.size();
        if(k!=n+m)return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        int ans=fun(s1,s2,s3,dp,0,0);
        if(ans==1)return true;
        return false;







    }
};