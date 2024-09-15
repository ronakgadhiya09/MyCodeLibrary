#include<bits/stdc++.h>

using namespace std;


class DSU{

    vector<int> parent;
    vector<int> rank;

    public:

    DSU(int n){
        parent.resize(n+1);
        for(int i = 1 ; i <= n ;i++) parent[i] = i;
        rank.resize(n+1,0);
    }

    int findfinalparent(int u){
        if(parent[u]==u) return u;

        return parent[u] = findfinalparent(parent[u]);
    }

    void unite(int u,int v){

        int u_parent = findfinalparent(u);
        int v_parent = findfinalparent(v);

        if(u_parent == v_parent) return;

        if(rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        }
        else if(rank[u_parent] < rank[v_parent]){
            parent[u_parent] = v_parent;
        }
        else{
            parent[v_parent] = u_parent;
            rank[u_parent] ++;
        }

    }

    bool isConnected(int u,int v){
        return findfinalparent(u) == findfinalparent(v);
    }

};

int main(){

    DSU obj(6);

    obj.unite(1, 2);
    obj.unite(2, 3);

    if (obj.isConnected(1, 3)) {
        cout << "1 and 3 are connected" << endl;
    } else {
        cout << "1 and 3 are not connected" << endl;
    }

    obj.unite(4, 5);
    obj.unite(4, 6);

    if (obj.isConnected(6, 3)) {
        cout << "6 and 3 are connected" << endl;
    } else {
        cout << "6 and 3 are not connected" << endl;
    }

    return 0;
}