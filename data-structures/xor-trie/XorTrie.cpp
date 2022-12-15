/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 15-12-2022
 *
 * XOR Trie is similar to a normal Trie and it stores the binary representation of numbers.
 * It is mainly used for finding the maximum XOR of two numbers.
 *
 * */

class XorTrie {
    struct TrieNode {
        int num;
        vector<TrieNode*> children;

        TrieNode() {
            this->num = -1;
            this->children = vector<TrieNode*>(2, NULL);
        }
    };

    TrieNode* root;

    public:

    XorTrie() {
        this->root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* curr = root;

        for(int i=30; i>=0; i--) {
            int currBit = (num>>i & 1);

            if(not curr->children[currBit]) {
                curr->children[currBit] = new TrieNode();
            }

            curr = curr->children[currBit];
        }

        curr->num = num;
    }

    int match(int num) {
        TrieNode* curr = root;

        for(int i=30; i>=0; i--) {
            int currBit = (num>>i & 1);

            if(curr->children[currBit ^ 1]) {
                curr = curr->children[currBit ^ 1];
            }
            else {
                curr = curr->children[currBit];
            }
        }

        return curr->num;
    }
};
