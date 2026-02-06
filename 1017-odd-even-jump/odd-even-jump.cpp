class Solution {
private:
    enum {ODD = 0, EVEN = 1};
public:
    int oddEvenJumps(vector<int>& arr) {

        int goodIndices;
        vector<vector<bool>> dp(arr.size(), {false, false});
        map<int, int> seen;
        map<int, int>::iterator closest;

        dp.back()[ODD] = true;
        dp.back()[EVEN]= true;
        goodIndices = 1;

        seen[arr.back()] = arr.size() - 1;

        for (int i = arr.size() - 2; i > -1; --i)
        {
            closest = seen.lower_bound(arr[i]);

            if (closest != seen.end() && closest->first == arr[i]) 
            {
                dp[i][ODD] = dp[closest->second][EVEN];
                dp[i][EVEN] = dp[closest->second][ODD];
            }
            else
            {
                dp[i][ODD] = ((closest != seen.end()) ? dp[closest->second][EVEN]: false); 

                if (closest == seen.begin()) 
                    dp[i][EVEN] = false;
                else
                {
                    --closest; 
                    dp[i][EVEN]= dp[closest->second][ODD];
                }
            }
            
            if (dp[i][ODD]) 
                ++goodIndices;

            seen[arr[i]] = i;
        }

        return goodIndices;
    }
};