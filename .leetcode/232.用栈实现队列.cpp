/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int>in,out;
    MyQueue() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int popnum=0;
        while(!in.empty()){
            int x=in.top();
            out.push(x);
            in.pop();
        }
        if(out.empty()){
            return 0;
        }else{
            popnum=out.top();
            out.pop();
        }
        while(!out.empty()){
            int x=out.top();
            in.push(x);
            out.pop();
        }
        return popnum;
    }
    
    int peek() {
        int popnum=0;
        while(!in.empty()){
            int x=in.top();
            out.push(x);
            in.pop();
        }
        if(out.empty()){
            return 0;
        }else{
            popnum=out.top();
        } 
        while(!out.empty()){
            int x=out.top();
            in.push(x);
            out.pop();
        }
        return popnum;
    }
    
    bool empty() {
        return in.empty();
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

