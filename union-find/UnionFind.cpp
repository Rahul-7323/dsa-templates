class UnionFind {

public:
    
	vector<int> parent;
    vector<int> rank;
    
    UnionFind(int n){
        parent = vector<int>(n);
        rank = vector<int>(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i; // parent of each node will be itself initially
            rank[i] = 0; // rank will be 0 for all nodes initially
        }
    }
    
    // finds the parent of given node u
    int Find(int u) {
        if(u == parent[u]){
            return u;
        }
        return u = Find(parent[u]);
    }
    
    // merges two sets into one, u and v belong to the corresponding sets
    void Union(int u, int v) {
        // find the parents of u and v
        u = Find(u);
        v = Find(v);
        
        // if u and v does not belong to the same set
        if(u != v){
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            
            // attach lower rank tree to higher rank tree
            parent[v] = u;
            
            if(rank[u] == rank[v]){
                rank[u]++;
            }
        }
    }
};
