class Solution {
public:
    int K;
    bool help(vector<int>& matchsticks, int target, int original_target, vector<bool>& used, int sides_done, int start) {
        if (sides_done == K-1) return true;
        
        if (target == 0) {
            return help(matchsticks, original_target, original_target, used, sides_done + 1, 0);
        }
        
        int n = matchsticks.size();
        for(int i = start; i < n; i++) {
            if (used[i] || matchsticks[i] > target) continue;
            
            if (i > 0 && matchsticks[i] == matchsticks[i-1] && !used[i-1]) continue;
            
            used[i] = true;
            if (help(matchsticks, target - matchsticks[i], original_target, used, sides_done, i + 1)) {
                return true;
            }
            used[i] = false;
            
            if (target == original_target) break;
        }

        return false;
    }
    
    
    bool canPartitionKSubsets(vector<int>& matchsticks, int k) {
        long long total = 0;
        for (int m : matchsticks) {
            total += m;
        }
        
        if (total == 0 || total % k != 0) {
            return false;
        }
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<bool> used(matchsticks.size(), false);
        K=k;
        
        return help(matchsticks, total / k, total / k, used, 0, 0);
    }
};