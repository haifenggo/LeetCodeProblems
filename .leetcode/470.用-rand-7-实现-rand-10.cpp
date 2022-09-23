/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a=rand7();
        int b=rand7();
        while(a>5){
            a=rand7();
        }
        switch(a){
        case 1:
            b=rand7(); while(b==4){b=rand7();}
            if(b<4){
                return 1;
            }else{return 2;}
            break;
        case 2:
            b=rand7(); while(b==4){b=rand7();}
            if(b<4){
                return 3;
            }else{return 4;}
            break;
        case 3:
            b=rand7(); while(b==4){b=rand7();}
            if(b<4){
                return 5;
            }else{return 6;}
            break;
        case 4:
            b=rand7(); while(b==4){b=rand7();}
            if(b<4){
                return 7;
            }else{return 8;}
            break;
        case 5:
            b=rand7(); while(b==4){b=rand7();}
            if(b<4){
                return 9;
            }else{return 10;}
            break;
        }
        return 0;
    }
};
// @lc code=end

