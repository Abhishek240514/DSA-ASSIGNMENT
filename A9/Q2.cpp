#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    dist[0][0] = a[0][0];
    pq.push({a[0][0], 0, 0});

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int cost = t[0], x = t[1], y = t[2];
        if(cost > dist[x][y]) continue;

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                int nc = cost + a[nx][ny];
                if(nc < dist[nx][ny]){
                    dist[nx][ny] = nc;
                    pq.push({nc, nx, ny});
                }
            }
        }
    }

    cout << dist[m-1][n-1];
}
