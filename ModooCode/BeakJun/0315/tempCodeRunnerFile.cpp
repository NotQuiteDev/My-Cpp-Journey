#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#define X first 
#define Y second 

string board[102];
bool vis[102][102];
int dist[102][102];
int dx[4] = {1,0,-1,0};
int n,m;
int dy[4] = {0,1,0,-1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i< n; i++) cin >> board[i];
    for(int i=0; i< n; i++) fill(dist[i], dist[i]+m, 999999);

    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;
    dist[0][0] = 1;
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir =0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >=n || ny >=m)continue;
            if(vis[nx][ny] || board[nx][ny] != '1')continue;
            Q.push({nx,ny});
            vis[nx][ny] = 1;
            dist[nx][ny] = min(dist[nx][ny], dist[cur.X][cur.Y]+1);
        }
    }
    cout << dist[n-1][m-1]<<"\n";

}