class Solution {
public:
    string vectorToString(vector<int>&v){
        string s;
        for(int i=0; i<v.size(); i++){
            s += to_string(v[i]);
        }
        return s;
    }
    unordered_map<string, int>dp;
    int solve(vector<int> need, vector<vector<int>>&special, vector<int>&price){
        // changing state is vector of need ->BY VALUE
        
        string key = vectorToString(need);
        if(dp.find(key) != dp.end()) return dp[key];

        // try for regular price
        int minCost = 0;
        for(int i=0; i<need.size(); i++){
            minCost += need[i] * price[i];
        }

        // try to minimise it using special offers
        for(auto &offer : special){
            vector<int>newNeeds = need;
            bool valid = true;

            // check if we can use this offer
            for(int i=0; i<need.size(); i++){
                if(offer[i] > need[i]){
                    valid = false;
                    break;
                }
                newNeeds[i] -= offer[i];
            }
            
            // If valid, try using this offer and recursively solve for remaining 
            if(valid){
                int offerPrice = offer.back();
                minCost = min(minCost, offerPrice + solve(newNeeds, special, price));
            }
        }
        return dp[key] = minCost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, 
            vector<int>& needs) {
        // Filter out offers that aren't actually deals
        vector<vector<int>>validOffers;
        for(auto &offer : special){
            int regularPrice = 0;
            for(int i=0; i<price.size(); i++){
                regularPrice += price[i] * offer[i];
            }
            if(offer.back() < regularPrice){
                validOffers.push_back(offer);
            }
        }
        return solve(needs, validOffers, price);
    }
};