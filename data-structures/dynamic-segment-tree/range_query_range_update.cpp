/*
 * A dynamic segment tree is a form of segment tree in which the nodes are allocated dynamically as and when needed.
 * This segment tree is used when we can't build all the nodes in advance due to a large size (1e9).
 *
 * Initially there will be a root node that represents the entire range, for example (0, 1e9). Whenever a query or
 * update is to be performed on some range, pointers to left and right child nodes are created recursively and the nodes
 * are dynamically allocated until the entire range can be represented by a single node. This allows us to perform queries 
 * on large ranges efficiently.
 *
 * The following code implements range maximum query and assignment of a value to a range.
 *
 * Time Complexity:-
 *      Range Query = O(log(n)) 
 *      Range Update = O(log(n))
 */

template<typename T=int>
struct SegTreeNode {
    int left, right;
    T val, lazy;
    SegTreeNode<T> *leftChild, *rightChild;
    T noOverlapVal = INT_MIN;

    SegTreeNode(int left, int right) {
        this->left = left;
        this->right = right;
        this->val = 0;
        this->lazy = -1;
        leftChild = NULL;
        rightChild = NULL;
    }

    void extend() {
        if(not leftChild and left != right) {
            int mid = (left + right) / 2;
            
            leftChild = new SegTreeNode<T>(left, mid);
            rightChild = new SegTreeNode<T>(mid+1, right);
        }
    }

    T operate(T a, T b) {
        return max(a, b);
    }

    void pull() {
        val = operate(leftChild->val, rightChild->val);
    }

    void push() {
        extend();

        if(lazy != -1) {
            val = lazy;

            if(left != right) {
                leftChild->lazy = lazy;
                rightChild->lazy = lazy;
            }

            lazy = -1;
        }
    }

    T query(int qs, int qe) {
        push();

        if(right < qs or left > qe) return noOverlapVal;

        if(left >= qs and right <= qe) return val;

        return operate(leftChild->query(qs, qe), rightChild->query(qs, qe));
    }

    T query(int i) {
        return query(i, i);
    }

    void update(int qs, int qe, T upd) {
        push();

        if(right < qs or left > qe) return;

        if(left >= qs and right <= qe) {
            lazy = upd;
            push();
            return;
        }

        leftChild->update(qs, qe, upd);
        rightChild->update(qs, qe, upd);

        pull();
    }
    
    void update(int i, T upd) {
        update(i, i, upd);
    }
};
