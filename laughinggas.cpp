#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N, M;
        cin>>M>>N;
        vector<vector<int> >grid(N, vector<int>(M, 0));
        vector<vector<int> >vis(N, vector<int>(M, 0));
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>grid[i][j];
            }
        }
        int sx, sy;
        cin>>sx>>sy;
        sx--;
        sy--; 
        queue<pair<pair<int, int>, int> > q;
        q.push(make_pair(make_pair(sx, sy), 1));
        int ans = 0;
        vis[sx][sy]=1;
        int dx[]={0, 0, -1, 1};
        int dy[]={-1, 1, 0, 0};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int level = q.front().second;
            q.pop();
            ans = max(ans, level);
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<N && ny<M && vis[nx][ny]==0 && grid[nx][ny]==1){
                    q.push(make_pair(make_pair(nx, ny), level+1));
                    vis[nx][ny]=1;
                }
            }
        }
        cout<<ans<<endl;


    }
}