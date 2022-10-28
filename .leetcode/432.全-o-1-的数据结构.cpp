/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
class AllOne {
public:
    list<pair<unordered_set<string>,int>>lt;
    unordered_map<string,list<pair<unordered_set<string>,int>>::iterator>mp;
    AllOne() {

    }
    
    void inc(string key) {
        if(mp.count(key)){
            auto cur=mp[key];
            auto nxt=next(cur);
            if(nxt==lt.end()||nxt->second>cur->second+1){
                unordered_set<string>s({key});
                mp[key]=lt.emplace(nxt,s,cur->second+1);
            }else{
                nxt->first.emplace(key);
                mp[key]=nxt;
            }
            cur->first.erase(key);
            if(cur->first.empty()){
                lt.erase(cur);
            }
        }else{
            if(lt.empty()||lt.begin()->second>1){
                unordered_set<string>s({key});
                lt.emplace_front(s,1);
            }else{
                lt.begin()->first.emplace(key);
            }
            mp[key]=lt.begin();
        }
    }
    
    void dec(string key) {
        auto cur=mp[key];
        if(cur->second==1){
            mp.erase(key);
        }else{
            auto pre=prev(cur);
            if(cur==lt.begin()||pre->second<cur->second-1){
                unordered_set<string>s({key});
                mp[key]=lt.emplace(cur,s,cur->second-1);
            }else{
                pre->first.emplace(key);
                mp[key]=pre;
            }
        }
        cur->first.erase(key);
        if(cur->first.empty()){
            lt.erase(cur);
        }
    }
    
    string getMaxKey() {
        return lt.empty()?"":*lt.rbegin()->first.begin();
    }
    
    string getMinKey() {
        return lt.empty()?"":*lt.begin()->first.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

