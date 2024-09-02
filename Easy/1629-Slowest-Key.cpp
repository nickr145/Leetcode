class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        // Initialize with the first key and its duration
        char slowestKey = keysPressed[0];
        int longestDuration = releaseTimes[0];

        // Iterate through the rest of the keypresses
        for (int i = 1; i < keysPressed.size(); ++i) {
            // Calculate the current key's duration
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            
            // Update if this key has a longer duration
            // Or if it has the same duration but is lexicographically larger
            if (duration > longestDuration || 
               (duration == longestDuration && keysPressed[i] > slowestKey)) {
                slowestKey = keysPressed[i];
                longestDuration = duration;
            }
        }

        return slowestKey;
    }
};
