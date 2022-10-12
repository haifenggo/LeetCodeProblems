/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
public:
    vector<int>t;
    int n;
    void build(int l,int r,int p,vector<int>&a){
        if(l==r){
            t[p]=a[l];return;
        }
        int mid=(l+r)/2;
        build(l,mid,p*2+1,a);
        build(mid+1,r,p*2+2,a);
        t[p]=t[p*2+1]+t[p*2+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        t.resize(n*4);
        build(0,nums.size()-1,0,nums);

    }
    void upd(int index,int val,int l,int r,int p){
        if(l==r){
            t[p]=val;return;
        }
        int mid=(l+r)>>1;
        if(index<=mid)upd(index,val,l,mid,p*2+1);
        else upd(index,val,mid+1,r,p*2+2);
        t[p]=t[p*2+1]+t[p*2+2];
    }
    int query(int L,int R,int l,int r,int p){
        if(l<=L&&R<=r){
            return t[p];
        }
        int mid=(L+R)>>1;
        int ans=0;
        if(l<=mid)ans+=query(L,mid,l,r,p*2+1);
        if(r>=mid+1)ans+=query(mid+1,R,l,r,p*2+2);
        return ans;
    }
    void update(int index, int val) {
        upd(index,val,0,n-1,0);

    }
    
    int sumRange(int left, int right) {
        return query(0,n-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

