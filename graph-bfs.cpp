#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
const int N = 1e5; 
int n,m; 
bool visited[N]; 

void bfs(int u) {
	queue<int> s;
	visited[u] = 1;
	s.push(u);
	while (!s.empty()) {
		int v = s.front();
		cout << v + 1 << " ";
		s.pop();
		for (int i = 0; i < graph[v].size(); i++)
			if (!visited[graph[v][i]]) {
				visited[graph[v][i]] = 1;
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
		cin >> a >> b ; 
		a--; b--; 
		graph[a].push_back(b);
		graph[b].push_back(a);// indirected graph
	}
	cout << "Begin a BFS from the node : " << endl;
	int node ; cin >> node ; node--;
	memset(visited, 0, n);
	bfs(node);
	
	return 0; 
}

