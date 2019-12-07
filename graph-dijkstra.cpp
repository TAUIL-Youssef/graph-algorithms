#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 ; 
vector<vector<pair<int,int> > > g ; 
int n,m ; 
int cost[N] ;  
int path[N] ;// array of stocking the paths

void dijkstra(int s){
    for(int i=0;i<n;i++)
        cost[i]=1e9 ; 
    cost[s]=0 ;
    for(int i=0;i<n;i++)
        path[i]=i ; // array for keeping track of the taken paths
	// example : p[1]=2 means that 1 -> 2 and so on... 
    priority_queue<pair<int,int> > pq ; // ( default order : ascendant maximum value )
    pq.push(make_pair(0,s)) ;
	//order priority based on the costs.
    while(!pq.empty()){
        int u=pq.top().second , cst=-pq.top().first ;
		//the minus sign stand for returning
        // to the real value, because we store negative costs 
		//to reverse the order.
        pq.pop() ; 
        if(cost[u]<cst)
            continue ;
        // for that condition , let assume that we have on the queue [ (-3,4),(-7,4)]
		//we begin by treating (-3,4), and because cost[4]=7 > cst=3 (at most 3) ,
		// there is no need to process the node 4 again with higther cost .    
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first , c=g[u][i].second;
            if(cost[v]>cst+c){
                cost[v]=cst+c ;
                path[v]=u ;
                pq.push(make_pair(-cost[v],v)) ;
            }
        }
    }
}

int main() {
	cout << "number of nodes : " ; cin >> n ;
	cout << "number of edges : " ; cin >> m ;
	g.clear();
	g.resize(n);
	// adjacency list inputs, let suppose the nodes from 1 to n
	cout << "let create some edges :" << endl;
	for(int i=0;i<m;i++){
		int a,b,w ; 
		cin >> a >> b >> w ; // edge from a to b with weight w
		a-- ; b-- ; 
		g[a].push_back(make_pair(b,w)) ;
		g[b].push_back(make_pair(a,w)) ;// indirected graph
	}
	int from,to ;
	cout << "Source : " ; cin >> from ;
	cout << "To : " ; cin >> to ; 
	from-- ; to-- ;
    dijkstra(from) ;
    cout <<"Shortest path from " << from+1 << " to " << to+1 << " is "<< cost[to] << endl;
    cout << "the path taken is through : " <<  endl;
    stack<int> ans ;
    ans.push(to) ;
    while(path[to]!=to){
        ans.push(path[to]) ;
        to=path[to] ;
    }
    while(!ans.empty()){
        cout<<ans.top()+1<<' ' ;
        ans.pop() ;
    }
	
	return 0;  
}

