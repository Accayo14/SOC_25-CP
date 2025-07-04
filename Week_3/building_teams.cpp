#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define pb push_back
#define vi vector<int>
#define lli long long int
using namespace std;
 
vi ar[100001];
bool vis[100001];
int color[100001];
 
bool dfs(int node , int c){
	vis[node] = true;
	color[node] = c;
	
	for(int v : ar[node])
	{
		if(vis[v] == false){
			bool res = dfs(v , c ^ 1);
			if(res == false) return false;
		}
		else{
			if(color[node] == color[v]) return false;
		}
	}
	
	return true;
}
 
int main()
{
	int a , b , n , m;
	cin>>n>>m;
	
	REP(i , m) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	
	bool flag = true;
	
	REP(i , n)
	if(vis[i] == false)
	{
		flag = dfs(i , 0);
		if(flag == false) break;
	}
	
	if(!flag) cout<<"IMPOSSIBLE";
	else
	REP(i , n) cout<<color[i] + 1<<" ";
}