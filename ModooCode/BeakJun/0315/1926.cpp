#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define X first 
#define Y second 

int board[502][502];
bool vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int k=0; k<m; k++){
            cin >> board[i][k];
        }
    }
    queue<pair<int,int>> Q;

    int cnt_drawing = 0;
    int max_drawing =0;

    for(int i=0 ; i< n; i++){
        for(int k=0; k<m; k++){
            if(vis[i][k] || board[i][k] != 1)continue;//이미 한바퀴 다 돈곳이거나 왔던곳인경우
            Q.push({i,k});
            cnt_drawing++;
            vis[i][k] = 1;
            int extent=1;
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop(); 
                for(int dir =0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m )continue;
                    if(vis[nx][ny] || board[nx][ny] != 1)continue;
                    Q.push({nx,ny});
                    vis[nx][ny] = 1;
                    extent++;
                }
            }
            max_drawing = max(extent, max_drawing);
        }
    }
    cout << cnt_drawing << "\n" << max_drawing << "\n";

}