class Solution {

    // Constants: large prime number for hashing
    private static final long MOD = 1_000_000_007;
    private static final long BASE = 97;

    public boolean isEqual(String s, long[] hash, long[] power, int start1, int start2, int length) {
        long hash1 = (hash[start1 + length] - hash[start1] * power[length] % MOD + MOD) % MOD;
        long hash2 = (hash[start2 + length] - hash[start2] * power[length] % MOD + MOD) % MOD;
        return hash1 == hash2;
    }

    public int deleteString(String s) {
        int n = s.length();
        int[] dp = new int[n];

        // Use -1 to indicate impossible states
        Arrays.fill(dp, -1); 

        // Precompute hash values and powers
        long[] hash = new long[n + 1];
        long[] power = new long[n + 1];
        power[0] = 1;
        hash[0] = 0;

        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * BASE + s.charAt(i)) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }

        // Compute the dp array
        for (int i = n - 1; i >= 0; i--) {

            // Minimum one operation (delete the whole substring)
            dp[i] = 1;
            for (int j = 1; i + j * 2 <= n; j++) {
                if (isEqual(s, hash, power, i, i + j, j)) {
                    if (dp[i + j] != -1) {
                        dp[i] = Math.max(dp[i], 1 + dp[i + j]);
                    }
                }
            }
        }

        return dp[0];
    }
}
