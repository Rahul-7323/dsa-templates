/*
 * Created By: Rahul M <roboto7o32oo3@gmail.com>
 *
 * UnionFind provides near constant-time operations to add new sets, to merge existing sets and to check whether elements are in the same set.
 * Mainly used for checking for connected components in graphs.
 *
 * Time Complexity: O(alpha(n)), where alpha(n) is the inverse Ackermann function. Since it is a very slowly growing function, the time complexity can be regareded as constant
 *  
 */

class UnionFind {

public:

    vector<int> parent, rank, size;

    UnionFind(int n) {
        parent.resize(n, -1);
        rank.resize(n, 0);
        size.resize(n, 1);
    }

    // finds the parent of given node u
    int find(int u) {
        // if the parent of the node is -1, then it is the root of the set 
        if(parent[u] == -1) return u;
        // else, find the parent while also compressing the paths
        return parent[u] = find(parent[u]);
    }

    // merges two sets into one, u and v belong to the corresponding sets
    // performs union by rank
    bool unionByRank(int u, int v) {
        // find the parents of u and v
        u = find(u);
        v = find(v);

        // if u and v does not belong to the same set
        if(u != v) {
            // if tree has lower rank
            if(rank[u] < rank[v]) {
                swap(u, v);
            }

            // attach lower rank tree to higher rank tree
            parent[v] = u;

            // if the ranks become equal, then increase the rank
            if(rank[u] == rank[v]) {
                rank[u]++;
            }

            return true;
        }

        return false;
    }

    // perform union by size
    bool unionBySize(int u, int v) {
        // find the parents of u and v
        u = find(u);
        v = find(v);

        // if u and v do not belong to the same set
        if(u != v) {
            // if size of u is smaller
            if(size[u] < size[v]) {
                swap(u, v);
            }

            // attach smaller size tree to larger size tree
            parent[v] = u;

            // the tree u now contains all the elements of v as well
            size[u] += size[v];

            return true;
        }

        return false;
    }
};
