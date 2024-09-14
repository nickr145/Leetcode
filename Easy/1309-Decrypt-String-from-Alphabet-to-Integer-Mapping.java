class Solution {
    public String freqAlphabets(String s) {
        StringBuilder result = new StringBuilder();
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            // Check if the current character is part of a '10#' to '26#' sequence
            if (i + 2 < n && s.charAt(i + 2) == '#') {
                // Extract the two digits and map them to 'j' to 'z'
                int num = (s.charAt(i) - '0') * 10 + (s.charAt(i + 1) - '0');
                result.append((char) ('j' + (num - 10)));
                i += 2; // Skip the next two characters ('10#' to '26#' are 3 characters long)
            } else {
                // Map '1' to '9' to 'a' to 'i'
                result.append((char) ('a' + (s.charAt(i) - '1')));
            }
        }

        return result.toString();
    }
}
