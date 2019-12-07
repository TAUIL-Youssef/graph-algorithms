#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
const int N = 1e5; 
int n,m; 
bool visited[N]; // for avoiding process the same node ( if vis[i]=true we continue )
// visited[N]={ 0 or false } because it's a global declaration for the variable

void dfs(int u) {
	visited[u] = 1;
	cout <<  u + 1 <<"  ";
	for (int i = 0; i < graph[u].size(); i++)
		if (!visited[graph[u][i]]){
			dfs(graph[u][i]);
		}
			
}

void dfs_stack(int u) {
	stack<int> s;
	visited[u] = 1;
	s.push(u);
	while (!s.empty()) {
		int v = s.top();
		cout << v + 1 <<"  ";
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
	cin >> n  ;
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
	cout << "Begin a DFS from the node : " << endl;
	int node ; cin >> node ; node--;
	cout << "the recursive version :" << endl;
	memset(visited, 0, n);// we fill the visited array with 0 of memory n ( n nodes )
	dfs(node);
	cout << endl;
	cout << "the stack version :" << endl;
	memset(visited, 0, n);// we refill the visited array with 0 of memory n ( n nodes )
	dfs_stack(node);
	
	return 0; 
}

