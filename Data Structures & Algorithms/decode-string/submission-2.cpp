class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;

        string current = "";
        int number = 0;

        for(char ch : s) {
            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            }
            else if (ch == '[') {
                st.push({current, number});
                current = "";
                number = 0;
            }
            else if (ch == ']') {
                auto [prev, repeat] = st.top();
                st.pop();

                string temp = prev;

                while (repeat--) {
                    temp += current;
                }

                current = temp;
            }
            else {
                current += ch;

            }
        }
        return current;
    }
};