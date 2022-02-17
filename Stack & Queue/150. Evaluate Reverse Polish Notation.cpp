#include <string>
#include <vector>
#include <stack>

class Solution
{
public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> st;

        for (std::string token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int num1 = st.top(); // num1 is originally the second element in tokens
                st.pop();
                int num2 = st.top(); // num2 is originally the fist element in tokens
                st.pop();

                if (token == "+")
                    st.push(num2 + num1);
                if (token == "-")
                    st.push(num2 - num1);
                if (token == "*")
                    st.push(num2 * num1);
                if (token == "/")
                    st.push(num2 / num1);
            }
            else
                st.push(stoi(token));
        }

        return st.top();
    }
};