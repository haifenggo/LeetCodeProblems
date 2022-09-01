/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int l=1,r=x,mid=0,sqrt=0;
        while(l<=r){
            mid=l+(r-l)/2;
            sqrt=x/mid;
            if(sqrt==mid){
                return mid;
            }else if(sqrt>mid){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return r;
    }
};
// @lc code=end

