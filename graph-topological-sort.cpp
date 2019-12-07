#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; 
vector<vector<int> >g; 
vector<int> in,canUse,ans;// in : indegree of nodes 
// canuse : the nodes with indegree=0 
// ans : flag for cycle
int n,m;  


int main() {
	cout << "number of nodes : ";
	cin >> n ;
	cout << "number of edges : ";
	cin >> m ;
	g.clear();
	g.resize(n);
	in.resize(n);
	// adjacency list inputs, let suppose the nodes from 0 to n-1
	cout << "let create some edges :" << endl;
	for(int i=0;i<m;i++){
		int a,b; 
		cin >> a >> b  ; // edge from a to b 
		g[a].push_back(b);
		in[b]++; // store the indegree for each vertex
	}
	// beginig vertices ( indegree[i]=0)
	for(int i=0;i<n;i++){
        if(in[i] == 0){ 
            canUse.push_back(i);
        }
    }
    while(!canUse.empty()){
        int u = canUse[canUse.size()-1];
        canUse.pop_back();
        ans.push_back(u);
        for(int i=0;i<g[u].size();i++){
            in[g[u][i]]--; // minimize the indegree by 1
            if(in[g[u][i]]==0){
                canUse.push_back(g[u][i]);
            }
        }
    }

    if(ans.size() != n){
        puts("Cycle detected !! ");
    }
    else{
        puts("One of the possible ranking is :");
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<((i==ans.size()-1)?"":" -> ");
        }
    }
    
	return 0;  
}

