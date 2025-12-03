#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, E, K;
    cin >> N >> E >> K;

    vector<vector<pair<int,int>>> g(N+1);
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    vector<int> dist(N+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;

        for(auto &p : g[u]){
            int v = p.first, w = p.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(dist[i] == 1e9){
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;
}
