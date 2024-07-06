/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        int tmp1=ans;
        q1.pop();
        q2.push(ans);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(q1.size())
            return false;
        else
            return true;
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
// @lc code=end

