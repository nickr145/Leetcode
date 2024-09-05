class Solution {
    public boolean findSubarrays(int[] nums) {
        // A HashSet ensures that any duplicate sums can be quickly detected.
        Set<Integer> seenSums = new HashSet<>();

        for (int i = 0; i < nums.length - 1; ++i) {
            int sum = nums[i] + nums[i+1];

            // Check if this sum has been seen before
            if (seenSums.contains(sum)) {
                return true;
            } else {
                // Add the current sum to the set
                seenSums.add(sum);
            }
        }
        // No such subarrays found
        return false;

    }
}
