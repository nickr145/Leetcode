class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to create powers array based on binary representation of n
    vector<int> powersOfTwoFromBinary(int n) {
        vector<int> powers;
        int power = 1;

        // Traverse through each bit of n
        for (int i = 0; n > 0; i++) {
            // Check if the current bit is set
            if (n & 1) {
                // Add the corresponding power of 2
                powers.push_back(power); 
            }
            // Move to the next power of 2
            power *= 2; 
            // Right shift n to check the next bit
            n >>= 1; 
        }

        return powers;
    }

    // Function to answer the product queries
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // Step 1: Create the powers array using the binary representation of n
        vector<int> powers = powersOfTwoFromBinary(n);
        vector<int> answers;

        // Step 2: Process each query
        for (const auto& q : queries) {
            int start = q[0];
            int end = q[1];
            long long product = 1; 

            // Step 3: Compute the product modulo MOD for each query
            for(int i = start; i <= end; ++i) {
                product = (product * powers[i]) % MOD;
            }

            // Step 4: Store the result
            answers.push_back(product);
        }

        return answers;
    }
};
