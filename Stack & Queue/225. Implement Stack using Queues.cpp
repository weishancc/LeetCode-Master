#include <queue>

class MyStack
{
public:
    std::queue<int> q1, q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        int size = q1.size();

        /* Back up the element from q2 to q1 so that q1 can pop until there is one elment left.
           After that, when we got the output, restore element from q2 to q1 and clear q2. */
        while (size > 1)
        {
            q2.push(q1.front());
            q1.pop();
            size--;
        }

        int res = q1.back();
        q1.pop();
        q1 = q2;
        while (!q2.empty())
            q2.pop();

        return res;
    }

    int top()
    {
        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */