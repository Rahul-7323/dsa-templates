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
    
    UnionFind(int n){
        parent = vector<int>(n);
        rank = vector<int>(n);
		size = vector<int>(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i; // parent of each node will be itself initially
            rank[i] = 0; // rank will be 0 for all nodes initially
			size[i] = 1; // size will be 1 for all nodes initially
        }
    }
    
    // finds the parent of given node u
    int find(int u) {
		// if the node is the parent of itself, then it is the root of the set 
        if(parent[u] == u) return u;
		// else, find the parent while also compressing the paths
        return parent[u] = find(parent[u]);
    }
    
    // merges two sets into one, u and v belong to the corresponding sets
	// performs union by rank
    void unionByRank(int u, int v) {
        // find the parents of u and v
        u = find(u);
        v = find(v);
        
        // if u and v does not belong to the same set
        if(u != v){
			// if tree has lower rank
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            
            // attach lower rank tree to higher rank tree
            parent[v] = u;
            
			// if the ranks become equal, then increase the rank
            if(rank[u] == rank[v]){
                rank[u]++;
            }
        }
    }

	// perform union by size
	void unionBySize(int u, int v) {
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
		}
	}
};
