class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1 || s == ")(") return 0;
        if (s == "()") return 2;

        stack<int> st;
        st.push(-1);

        int maxLen = 0;

        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (!st.empty()) {
                    maxLen = max(maxLen, i - st.top());
                } else {
                    st.push(i);
                }
            }
        }

        return maxLen;

    }
};
