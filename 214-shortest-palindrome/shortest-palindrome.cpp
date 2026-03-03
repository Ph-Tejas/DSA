class Solution {
public:
vector<int> zFunction(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l;
            
            // Case 2: reuse the previously computed value
            z[i] = min(r - i + 1, z[k]);
        }

        // Try to extend the Z-box beyond r
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        // Update the [l, r] window if extended
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}
    string shortestPalindrome(string s) {
        
        int n=s.size();
        string s_=s;
        reverse(s_.begin(),s_.end());
        vector<int>z=zFunction((s+"$")+s_);
        int ans=0;
        for(int i=2*n;i>-1;i--){
            if(i+z[i]==2*n+1)ans=i;
        }
        int ind=2*n-ans+1;
        string fin;
        for(int i=n-1;i>ind-1;i--){
            fin.push_back(s[i]);
        }
        return fin+s;




    }
};