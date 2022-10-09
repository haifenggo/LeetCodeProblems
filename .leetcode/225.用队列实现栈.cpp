/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int>in,out;
    MyStack() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        while(in.size()!=1){
            out.push(in.front());
            in.pop();
        }
        int x=in.front();
        in.pop();
        while(!out.empty()){
            in.push(out.front());
            out.pop();
        }
        return x;
    }
    
    int top() {
        while(in.size()!=1){
            out.push(in.front());
            in.pop();
        }
        int x=in.front();
        out.push(x);
        in.pop();
        while(!out.empty()){
            in.push(out.front());
            out.pop();
        }
        return x;
    }
    
    bool empty() {
        return in.empty();
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

