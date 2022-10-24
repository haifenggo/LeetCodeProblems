/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    vector<Trie*>child;
    bool isEnd;
    Trie* findprefix(string str){
        Trie* node=this;
        for(char ch:str){
            int i=ch-'a';
            if(node->child[i]==nullptr)return nullptr;
            node=node->child[i];
        }
        return node;
    }
    Trie():child(26),isEnd(false) {

    }
    
    void insert(string word) {
        Trie* node=this;
        for(char ch:word){
            int i=ch-'a';
            if(node->child[i]==nullptr){
                node->child[i]=new Trie();
            }
            node=node->child[i];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        Trie* node=this->findprefix(word);
        return node!=nullptr&&node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node=this->findprefix(prefix);
        return node!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

