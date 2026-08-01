class MinStack {

    stack<int> ns;
    stack<int> min;
public:
   
    
    void push(int value) {
        ns.push(value);

        if(min.empty() || value<=min.top())
        {
            min.push(value);
        }

    }
    
    void pop() {
        if(ns.top()==min.top())
        {
            min.pop();
        }
        ns.pop();
    }
    
    int top() {
        return ns.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */