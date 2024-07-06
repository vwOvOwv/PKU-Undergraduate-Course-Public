/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    int mini_val;
    stack<int>data;
    MinStack() {
        mini_val=INT_MAX;
    }
    
    void push(int val) {
        data.push(val);
        if(min.empty()){
            min.push(val);
        }
        else{
            while(!min.empty()&&min.top()<=val)
                min.pop();
            
        }
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mini_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

