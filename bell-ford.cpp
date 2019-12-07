#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; 
vector<vector<pair<int,int> > >g; 
int n,m; 
int dist[N];  
int path[N];// array of stocking the paths

void bellman_ford(int s){
    
	for(int i=0;i<n;i++)
        dist[i]=1e9;
    
	dist[s]=0;
    
for(int i=0;i<n;i++)
        dist[i]=1e9;
    dist[s]=0;

    for(int k=0;k<n;++k){
        bool flag = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                if(dist[g[i][j].first]>dist[i]+g[i][j].second){
                    dist[g[i][j].first] = dist[i]+g[i][j].second ;
                    flag = false;
                }
            }
        }
        for(int i=0;i<n;i++)
        cout << dist[i]<<"  " ;
        cout << endl;
        if(flag)
            break;
    }
	for(int i=0;i<n;i++)
        cout << dist[i]<<"  " ;
    
}


int main() {
	cout << "number of nodes : ";
	cin >> n ;
	cout << "number of edges : ";
	cin >> m ;
	g.clear();
	g.resize(n);
	// edgeslist inputs, let suppose the nodes from 1 to n
	cout << "let create some edges :" << endl;
	for(int i=0;i<m;i++){
		int a,b,w; 
		cin >> a >> b >> w ; // edge from a to b with weight w
		//a--; b--; 
		g[a].push_back(make_pair(b,w));
		//g[b].push_back(make_pair(a,w));// indirected graph
	}
	cout << "Shortest path from root to given destination : " << endl;
	int root,destination ; cin >> root >> destination ; 
	bellman_ford(root);
//    cout <<"the answer is: "<< cost[destination] << endl;
//    cout << "the path taken is through : " <<  endl;
//    stack<int> ans;
//    ans.push(destination);
//    while(path[destination]!=destination){
//        ans.push(path[destination]);
//        destination=path[destination];
//    }
//    while(!ans.empty()){
//        cout<<ans.top()+1<<' ';
//        ans.pop();
//    }
	
	return 0;  
}

