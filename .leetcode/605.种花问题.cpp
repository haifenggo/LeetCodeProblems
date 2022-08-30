/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool can=1;
        int siz=flowerbed.size();
        for(int i=0;i<siz;i++){
            if(flowerbed[i]==1){
                can=0;
            }else{
                if(can&&(i+1==siz||(i+1<siz&&flowerbed[i+1]==0))){
                    n--;
                    can=false;
                }else{
                    can=true;
                }
            }
        }
        return n<=0;
    }
};
// @lc code=end

