class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<long, long>> s;
    long mini;
    MinStack() {
    }

    void push(long x) {
        long mini;
        if (s.size() == 0) {
            mini = x;
        }
        else {
            mini = x<getMin()?x:getMin();
        }
        s.push(make_pair(x, mini));
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
