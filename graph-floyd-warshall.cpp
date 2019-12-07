#include<bits/stdc++.h>
using namespace std;
const int MX = 1000;
const int INF = 1e9;
int n,m;
int cost[MX][MX],from,to;

int main(){

    cout << "number of nodes : ";
	cin >> n ;
	cout << "number of edges : ";
	cin >> m ;
	// adjacency matrix cost
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cost[i][j] = ((i==j)?0:INF);
	// adjacency matrix edges inputs from 0 to n-1
	cout << "let create some edges :" << endl;
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w ;// from a to b with weight w
		cost[a][b]=w ;
	}
	// floyd-warshall code
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
    }

    cout<<"Source : "; cin>>from;
    cout<<"To : "; cin>>to;
    
    int x = cost[from][to];

    cout<<"Shortest path from "<<from<<" To "<<to<<" is "<< x;

return 0;

}


