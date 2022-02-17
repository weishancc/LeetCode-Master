#include <string>
#include <stack>
#include <algorithm>

class Solution
{
public:
    std::string removeDuplicates(std::string s)
    {
        std::stack<char> st;

        for (char c : s)
        {
            if (st.empty() || st.top() != c)
                st.push(c);
            else
                st.pop();
        }

        std::string res;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        std::reverse(res.begin(), res.end()); // Lastly we need to reverse the string because stack is FILO
        return res;
    }
};


// /* How if directly use string as stack -> Save the time of reversing */
// class Solution
// {
// public:
//     std::string removeDuplicates(std::string s)
//     {
//         std::string res;

//         for (char c : s)
//         {
//             if (res.empty() || res.back() != c)
//                 res.push_back(c);
//             else
//                 res.pop_back();
//         }
//         return res;
//     }
// };