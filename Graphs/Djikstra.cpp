#include <iostream>
#include <set> 
#include <iterator>
#include <bitset> 
#include <bits/stdc++.h> 
using namespace std;
typedef  long long int ll;
ll mod=1000000007;

ll d[100100];
vector <pair<int,int>> g[100100];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;// NUMBER OF NODES AND EDGES
        for(int i=0;i<m;i++){
            int x,y,w;// EDGE FROM (u,v) with weight w
            cin>>x>>y>>w;
            g[x].push_back({y,w});
        }
        
        for(int i=1;i<=n;i++){
            d[i] = 1e18;
        }
        
        d[1] = 0;
        
        set <pair<ll,int>> q;
        q.insert({0,1});
        
        while(!q.empty()){
            auto it = *q.begin();
            ll len = it.first;
            int u = it.second;
            q.erase(it);
            for(auto v:g[u]){
                if(d[v.first] >  len + v.second){
                    
                    auto it = q.find({d[v.first],v.first});
                    if(it!=q.end()) q.erase(*it);
                    d[v.first] = len + v.second;
                    q.insert({d[v.first],v.first});
                }
            }
        }
        
        for(int i=1;i<=n;i++)
            cout<<d[i]<<" ";
        
    
        
    
        
    }
    return 0;
}
