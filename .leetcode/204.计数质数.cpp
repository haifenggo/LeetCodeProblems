/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:

    int countPrimes(int n) {
        int prime[n+5];
        bool vis[n+2];
        for(int i=0;i<=n;i++){
            vis[i]=0;
        }
        int cnt=0;
        for (int i = 2;i < n;i++)
        {
            if (!vis[i])
                prime[cnt++]=i;
            for (int j = 0;j < cnt;j++)//对于每个素数
            {
                if (i * prime[j] > n)break;//当前这个数和前面任意素数的乘积不在n范围内，更大的素数乘积更大，故break
                vis[i * prime[j]] = true;//筛去当前这个数和前面任意素数的乘积
                if (i % prime[j] == 0)break;//当前数是前面素数的倍数，已经有公因子了，不用再筛
            }
        }
        return cnt;
    }
};
// @lc code=end

