#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph{
    int v;
    list<int> *adj;
    
    public:
    Graph(int v){
        this->v=v;
        adj=new list<int>[v];
    }
    
    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
    
    int n,q,i;
    cin>>n;
    int s[n];
    
    for(i=0;i<n;i++)
        cin>>s[i];
    
    Graph gsA(n), gsB(n);
    
    //cin>>q;
    int u,v;
    
    for(i=0;i<n-1;i++){
        cin>>u>>v;
        gsA.addEdge(u,v);
        gsB.addEdge(u,v);
    }
    
    cin>>q;
    
    int a,b,c,d;
    
    for(i=0;i<q;i++){
        cin>>u>>v;
        func(gsA, gsB,u,v,&a,&b,&c,&d);
    }
    
    cout<<a<<b<<c<<d;
    
    
    
    
}
