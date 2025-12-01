class DSU{
    vector<int> parent,rank;
public:
    DSU(int n){
        this->parent.resize(n);
        iota(this->parent.begin(),this->parent.end(),0);
        this->rank.resize(n,0);
    }

    int findParent(int node){
        //path compression
        if(node!=parent[node])
            return parent[node]=this->findParent(parent[node]);
        return node;
    }

    void merge(int node1,int node2){
        int node1Parent=this->findParent(node1);
        int node2Parent=this->findParent(node2);
        if(node1Parent==node2Parent)
            return ;
        if(rank[node1Parent] < rank[node2Parent]){
            parent[node1Parent]=node2Parent;
        } else if(rank[node1Parent] > rank[node2Parent]){
            parent[node2Parent]=node1Parent;
        } else {
            //assign the node1/node2 as representative node
            parent[node1Parent]=node2Parent;
            rank[node2Parent]++;
        }
        return ;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            dsu.merge(u,v);
        }
        int connectedComponentsCount=0;
        for(int i=0;i<n;i++)
            connectedComponentsCount+=(dsu.findParent(i)==i);

        return connectedComponentsCount;
    }
};
