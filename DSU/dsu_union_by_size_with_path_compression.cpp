class DSU{
    vector<int> parent,size;
public:
    DSU(int n){
        this->parent.resize(n);
        iota(this->parent.begin(),this->parent.end(),0);
        this->size.resize(n,1);
    }

    int findParent(int node){
        //path compression
        if(node!=parent[node])
            return parent[node]=this->findParent(parent[node]);
        return node;
    }

    void merge(int node1,int node2){
        int node1Parent=findParent(node1);
        int node2Parent=findParent(node2);
        if(node1Parent==node2Parent)
            return ;
        if(size[node1Parent] < size[node2Parent]){
            size[node2Parent]+=size[node1Parent];
            parent[node1Parent]=node2Parent;
        } else {
            size[node1Parent]+=size[node2Parent];
            parent[node2Parent]=node1Parent;
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
