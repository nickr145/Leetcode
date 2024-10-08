class Solution {
public:
    int numTrees(int n) {
        // Create a DP array to store the number of unique BSTs for each size
        vector<int> dp(n + 1, 0);
        
        // Base cases
        dp[0] = 1; // Empty tree
        dp[1] = 1; // Tree with one node

        // Fill the DP table for all values from 2 to n
        for (int nodes = 2; nodes <= n; ++nodes) {
            for (int root = 1; root <= nodes; ++root) {
                // Left subtree has 'root-1' nodes and right subtree has 'nodes-root' nodes
                dp[nodes] += dp[root - 1] * dp[nodes - root];
            }
        }

        return dp[n];
    }
};
