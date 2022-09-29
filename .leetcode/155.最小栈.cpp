/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    stack<int>stk,mn;
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if(mn.empty()||mn.top()>=val){
            mn.push(val);
        }
    }
    
    void pop() {
        if(stk.empty()){return;}
        int x=stk.top();
        stk.pop();

        if(!mn.empty()&&x==mn.top()){
            mn.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mn.top();
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

