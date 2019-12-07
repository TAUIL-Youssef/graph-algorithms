#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; 
vector<vector<pair<int,int> > >g; 
int n,m; 
int cost[N];  
int path[N];

void bellman_ford(int s){
    
	for(int i=0;i<n;i++)
        cost[i]=1e9;
    
	cost[s]=0;
    
    for(int k=0;k<n;++k){
        bool flag = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
            	int v=g[i][j].first , c=g[i][j].second;// i -> v with cost c
                if(cost[v]>cost[i]+c){
                    cost[v] = cost[i]+c ;
                    path[v]=i;
                    flag = false;
                }
            }
        }
        if(flag)// we finish the process if the costs still the same
            break;
    }
	
}


int main() {
	cout << "number of nodes : ";
	cin >> n ;
	cout << "number of edges : ";
	cin >> m ;
	g.clear();
	g.resize(n);
	// edgeslist inputs, let suppose the nodes from 0 to n-1
	cout << "let create some edges :" << endl;
	for(int i=0;i<m;i++){
		int a,b,w; 
		cin >> a >> b >> w ; // edge from a to b with weight w
		//a--; b--; 
		g[a].push_back(make_pair(b,w));
		//g[b].push_back(make_pair(a,w));// indirected graph
	}
int from,to ;
	cout << "Source : " ; cin >> from ;
	cout << "To : " ; cin >> to ; 
	//from-- ; to-- ;
    bellman_ford(from) ;
    cout <<"Shortest path from " << from << " to " << to << " is "<< cost[to] << endl;
    cout << "the path taken is through : " <<  endl;
    stack<int> ans ;
    ans.push(to) ;
    while(path[to]!=to){
        ans.push(path[to]) ;
        to=path[to] ;
    }
    while(!ans.empty()){
        cout<<ans.top()<<' ' ;
        ans.pop() ;
    }
	
	return 0;  
}

