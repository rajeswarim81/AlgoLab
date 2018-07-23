#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<list>
#include<queue>
#include<stack>
using namespace std;

int min(int a, int b){
	return (a<b?a:b);
}

int max(int a, int b){
	return (a>b?a:b);
}

class Graph{
	int v;
	list<int> *adj;

public:
	Graph(int n);
	void addEdge(int u, int w);
	void BFS(int s);
	void DFS(int s);
	void DFSU(int u, bool *visited);
};

Graph::Graph(int n){
	v=n;
	adj=new list<int>[n];
}
void Graph::addEdge(int u, int w){

	adj[u].push_back(w);
}

void Graph::BFS(int s){
	bool *visited=new bool[v];
	int i;
	for(i=0;i<v;i++)
		visited[i]=false;

	list<int> q; int t;

	visited[s]=true;
	q.push_back(s);
	list<int>::iterator iq;

	while(!q.empty()){
      s=q.front();
      cout<<q.front()<<"\t";
      q.pop_front();
     // cout<< *adj[s].begin()<<"\t"<<*adj[s].end();

      for(iq=adj[s].begin(); iq!=adj[s].end();iq++){

      	if(!visited[*iq]){
            q.push_back(*iq);
      	    visited[*iq]=true;
      }

      }
	}
}

void Graph:: DFSU(int u, bool *visited){

	//stack<int> st;
	//st.push(u);
	list<int>::iterator it;

	  cout<<u<<"\t";
        
        for(it=adj[u].begin(); it!=adj[u].end();it++){
        	if(!visited[*it]){
        		//st.push(*it);
        		visited[*it]=true;
        		DFSU(*it,visited);
        	}
        }
	

}

void Graph:: DFS(int s){
	bool *visited=new bool[v];

	int i;
	for(i=0;i<v;i++)
		visited[i]=false;
	visited[s]=true;

	DFSU(s,visited);
}

main(){
	   Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
    cout<<"\n";
    //cout<<"check";
  
}