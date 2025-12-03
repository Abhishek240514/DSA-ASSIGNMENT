#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<int>> &g, vector<vector<bool>> &vis){
    vis[x][y] = true;
    int m = g.size(), n = g[0].size();
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(nx>=0 && ny>=0 && nx<m && ny<n && g[nx][ny]==1 && !vis[nx][ny])
            dfs(nx, ny, g, vis);
    }
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>> g(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int cnt = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == 1 && !vis[i][j]){
                cnt++;
                dfs(i, j, g, vis);
            }
        }
    }

    cout << cnt;
}
