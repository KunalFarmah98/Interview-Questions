 class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // creating an unordered set for a quick lookup
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        
        // hash table as a memo
        unordered_map<string, bool> memo;
        return wordBreak(s, wordSet, memo);
    }
    
    bool wordBreak(const string& s, const unordered_set<string>& wordSet, unordered_map<string, bool>& memo) {
        
        // if string is in memo, return its ans
        auto it = memo.find(s);
        if (it != memo.end()) 
            return it->second;
        
        // if entire string is present, we are done
        if (wordSet.find(s) != wordSet.end()) 
            return memo[s] = true;
        
        // else try partitioning
        
        // no need to check for left and right separately 
        // right decides if left is possible
        
        for (int pos = 1; pos < s.size(); ++pos) {
            // First Check whether right part is in word set as it is the decisive factor
            const string right = s.substr(pos);
            // if not found, continue
            if (wordSet.find(right) == wordSet.end())
                continue;
            
            // Check whether left part can be segmented
            const string left = s.substr(0, pos);           
            if (wordBreak(left, wordSet, memo))
                return memo[s] = true;
        }
        
        // No partition found for s
        return memo[s] = false;
    }

};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        int n = s.size();

        // a 1-D dp is enough to check if its possible or not
        // it stores if length i is present in dictionary or not
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        // Topological order
        for (int i = 1; i <= n; ++i) {
            // partitions starting frome entire string to one char at a time
            for (int j = 0; j <= i - 1; ++j) {
               // check if left part is possible
                if (dp[j]) {
                    // if yes, then check if right part is present or not
                    const string sub = s.substr(j, i - j);
                    if (wordSet.find(sub) != wordSet.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        // last element will have ans
        
        return dp[n];
    }
};