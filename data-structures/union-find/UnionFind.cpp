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
    vector<int> parent, size;
    
    UnionFind(int n) {
        parent.assign(n, -1);
        size.assign(n, 1);
    }
    
    int find(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent[u]);
    }
    
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        
        if(u == v) return false;
        
        if(size[u] < size[v]) swap(u, v);
        
        parent[v] = u;
        size[u] += size[v];
        
        return true;
    }
};
