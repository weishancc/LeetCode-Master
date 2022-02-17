#include <string>
#include <stack>

class Solution
{
public:
    /* There are three invalid cases:
       Case1: There are redundant left parentheses.
       Case2: There are redundant right parentheses.
       Case3: There is no redundant parentheses, but type isn't matched. */

    bool isValid(std::string s)
    {
        std::stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            /* Push right parentheses to stack so that we can conviniently compare top element w/ s[i] */
            if (s[i] == '(')
                st.push(')');
            else if (s[i] == '[')
                st.push(']');
            else if (s[i] == '{')
                st.push('}');
            else if (st.empty()) // Case2
                return false;
            else if (s[i] != st.top()) // Case3
                return false;
            else
                st.pop();
        }

        return st.empty(); // Case1
    }
};