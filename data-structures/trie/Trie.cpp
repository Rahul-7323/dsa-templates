class Trie {
    
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        bool isLeaf = false;
    };
    
    TrieNode* root;
    
public:
    
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        
        for(char& c : word){
            if(not curr->children.count(c)){
                curr->children[c] = new TrieNode();
            }
            
            curr = curr->children[c];
        }
        
        curr->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        
        for(char& c : word){
            if(not curr->children.count(c)){
                return false;
            }
            
            curr = curr->children[c];
        }
        
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(char& c : prefix){
            if(not curr->children.count(c)){
                return false;
            }
            
            curr = curr->children[c];
        }
        
        return true;
    }
};
