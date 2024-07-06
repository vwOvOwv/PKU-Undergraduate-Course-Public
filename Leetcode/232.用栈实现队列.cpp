/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s1.top();
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s1.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(s1.size())
            return false;
        else
            return true;
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
// @lc code=end

