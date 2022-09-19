/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:

    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;
        for(int i=0;i<expression.size();i++){
            char ch=expression[i];
            if(ch=='-'||ch=='+'||ch=='*'){
                vector<int>left=diffWaysToCompute(expression.substr(0,i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1));
                for(const int& l:left){
                    for(const int & r:right){
                        if(ch=='-'){
                            ans.push_back(l-r);
                        }else if(ch=='+'){
                            ans.push_back(l+r);
                        }else{
                            ans.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(ans.empty())ans.push_back(stoi(expression));
        return ans;
    }
};
// @lc code=end

