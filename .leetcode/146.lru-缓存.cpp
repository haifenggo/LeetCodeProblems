/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct DLinkedNode {
    int key, val;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode(): key(0), val(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), val(_value), pre(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    unordered_map<int,DLinkedNode*>cache;
    int size;
    int capacity;
    DLinkedNode* head,*tail;
    LRUCache(int cap):capacity(cap) ,size(0){
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->next=tail;
        tail->pre=head;
    }
    void add(DLinkedNode* cur){
        cur->pre=head;
        cur->next=head->next;
        head->next=cur;
        cur->next->pre=cur;
    }
    void remove(DLinkedNode* cur){
        cur->pre->next=cur->next;
        cur->next->pre=cur->pre;
    }
    void tohead(DLinkedNode* cur){
        remove(cur);
        add(cur);
    }
    DLinkedNode* deltail(){
        DLinkedNode* cur=tail->pre;
        remove(cur);
        return cur;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkedNode* cur=cache[key];
        tohead(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            DLinkedNode* cur=new DLinkedNode(key,value);
            if(size==capacity){
                DLinkedNode *removed = deltail();
                cache.erase(removed->key);
                delete removed;
                add(cur);
            }else{
                size++;
                add(cur);
            }
            cache[key]=cur;
        }else{
            cache[key]->val=value;
            tohead(cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

