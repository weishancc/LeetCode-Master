#include <stack>

class MyQueue
{
public:
    std::stack<int> stIn, stOut;

    MyQueue()
    {
    }

    void push(int x)
    {
        stIn.push(x);
    }

    /* If stOut is empty, put all elements in stIn to stOut*/
    int pop()
    {
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }

        int res = stOut.top();
        stOut.pop();

        return res;
    }

    int peek()
    {
        /* Reuse the code in pop(), but we need to push res back! */
        int res = this->pop();
        stOut.push(res);

        return res;
    }

    bool empty()
    {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */