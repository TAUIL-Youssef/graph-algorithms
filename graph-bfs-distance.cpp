#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
const int N = 1e5; 
int n,m; 
bool visited[N]; 
int dist[N]={0}; // array of distance for each node 
int path[N];// array of stocking the paths

void bfs_distance(int u) {
	for(int i=0;i<n;i++)
        path[i]=i;
	queue<int> s;
	visited[u] = 1;
	s.push(u);
	while (!s.empty()) {
		int v = s.front();
		s.pop();
		for (int i = 0; i < graph[v].size(); i++)
			if (!visited[graph[v][i]]) {
				visited[graph[v][i]] = 1;
				dist[graph[v][i]]=dist[v]+1;
				path[graph[v][i]]=v;
				s.push(graph[v][i]);
			}
	}
}


int main() {
	cout << "number of nodes : ";
	cin >> n ;
	cout << "number of edges : ";
	cin >> m ;
	graph.clear();
	graph.resize(n);
	// adjacency list inputs, let suppose the nodes from 1 to n
	cout << "let create some edges :" << endl;
	for(int i=0;i<m;i++){
		int a,b; 
		cin >> a >> b ; // edge from a to b with weight w
		a--; b--; 
		graph[a].push_back(b);
		graph[b].push_back(a);// indirected graph
	}
	cout << "Shortest path from root to given destination : " << endl;
	int root,destination ; cin >> root >> destination ; root--; destination--;
	memset(visited, 0, n);
	bfs_distance(root);
	cout <<"the answer is: "<< dist[destination] << endl;
	cout << "the path taken is through : " <<  endl;
	stack<int> ans;
    ans.push(destination);
    while(path[destination]!=destination){ // every time path[i]!=i there is path
        ans.push(path[destination]);// we add the node of the path
        destination=path[destination];// continue the process on the new node 
    }
    while(!ans.empty()){
        cout<<ans.top()+1<<' ';
        ans.pop();
    }
	
	return 0;  
}

