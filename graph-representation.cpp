#include <bits/stdc++.h>
using namespace std;

int n,m;  // n: number of nodes ; m: number of edges
vector<vector< pair<int,int> > > graph; // adjacency list of weighted graph

int main() {
	cout << " number of nodes : ";
	cin >> n  ;
	cout << " number of edges : ";
	cin >> m ;
	graph.clear();
	graph.resize(n);
	// adjacency list inputs, let suppose the nodes from 1 to n
	cout << " let create some edges :" << endl;
	for(int i=0;i<m;i++){
		int a,b,w; 
		cin >> a >> b >> w ; // edge from a to b with weight w 
		a--; b--; 
		// we use the case memory [0] for node 1, 1 for 2 ... and so on,
		// to minimize the memory 
		// we can declare resize(n+1) but it waste 
		//of case graph[0] from the vector .
		graph[a].push_back(make_pair(b,w));
		graph[b].push_back(make_pair(a,w));// indirected graph
	}
	cout << "The adjacency list is :" << endl;
	for(int i=0;i<n;i++){ // loop for nodes
		int node=i;
		cout << node +1 << " : ";
		for(int j=0;j<graph[i].size();j++){// loop for connected edges 
			cout << "(" << graph[i][j].first + 1 << " , " << graph[i][j].second << ")"
			<<((j==graph[i].size()-1)?"":";") ;
		}
		cout << endl ;
	}
	
	return 0; 
}

