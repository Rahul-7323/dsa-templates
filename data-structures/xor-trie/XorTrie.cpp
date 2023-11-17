/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 15-12-2022
 *
 * XOR Trie is similar to a normal Trie and it stores the binary representation of numbers.
 * It is mainly used for finding the maximum XOR of two numbers.
 *
 * */

class XOR_Trie {
public:
    struct TrieNode {
        TrieNode* children[2] = {NULL};
        int count = 0;
    };

    int n;
    TrieNode* root = new TrieNode();

    XOR_Trie(int n) {
        this->n = n;
    }

    void insert(int num) {
        TrieNode* curr = root;

        for(int i=n-1; i>=0; i--) {
            int bit = ((num>>i) & 1);

            if(not curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }

            curr = curr->children[bit];
            curr->count++;
        }
    }

    void remove(int num) {
        TrieNode* curr = root;

        for(int i=n-1; i>=0; i--) {
            int bit = ((num>>i) & 1);

            curr = curr->children[bit];
            curr->count--;
        }
    }

    int max_xor(int num) {
        TrieNode* curr = root;
        int val = 0;

        for(int i=n-1; i>=0; i--) {
            int bit = ((num>>i) & 1);

            if(curr->children[bit ^ 1] and curr->children[bit ^ 1]->count > 0) {
                val |= (1<<i);
                curr = curr->children[bit ^ 1];
            }
            else {
                curr = curr->children[bit];
            }
        }

        return val;
    }
};
