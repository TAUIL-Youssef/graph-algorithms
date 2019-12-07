#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
const int N = 100000;
int n,m;

int indx[N],low[N],dfsTime;// time of visited node by DFS 
// low stand for the indx[lowest children]   
vector<int> s;//the visited vertices
bool vis[N];
int compID[N] ,cmp;// components wuth same id

void DFS(int u){
    indx[u] = low[u] = ++dfsTime;
    s.push_back(u);
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(indx[v]==0)
            DFS(v);
        if(vis[v])
            low[u]=min(low[u],low[v]);
    }
    if(indx[u]==low[u]){
        while(true){
            int v=s.back();
            s.pop_back();
            vis[v]=false;
            compID[v]=cmp;
            if(v==u)
                break;
        }
        ++cmp;
    }
}

int main(){

    cout << "number of nodes : ";
	cin >> n ;
	cout << "number of edges : ";
	cin >> m ;
    g.clear();
    g.resize(n);
    
	cout << "let create some edges :" << endl;
    for(int i=0;i<m;i++){
        int a,b;
		cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=0;i<n;i++)
        if(indx[i]==0)
            DFS(i);
	
	
	vector<vector<int> >res;
	res.resize(cmp);
	for(int i=0;i<n;i++){
		res[compID[i]].push_back(i);
	}
	cout<<"Their are "<<cmp<<" strongly components :"<<endl;
	for(int i=0;i<cmp;i++){
		cout<<"Elements of component "<<i+1<<" are :"<<endl<<"{";
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<((j==res[i].size()-1)?"":",");
		}
		cout<<"}"<<endl;
	}
	

    return 0;
}
