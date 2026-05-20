class Solution {
public:
    
    long long target;
    int ans = 0;

    unordered_map<long long,int> mp;

    void dfs(TreeNode* node, long long currSum) {
        if(node == NULL) return;

        currSum += node->val;

        // number of previous prefix sums
        // such that currSum - prev = target
        ans += mp[currSum - target];

        mp[currSum]++;

        dfs(node->left, currSum);
        dfs(node->right, currSum);

        // backtrack
        mp[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        
        target = targetSum;

        mp[0] = 1;

        dfs(root, 0);

        return ans;
    }
};