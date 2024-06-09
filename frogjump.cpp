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
    int T; cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<vector<int> > grid(n, vector<int>(n, 0));
        vector<vector<int> > cost_grid(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>grid[i][j];
            }
        }
        int sx, sy, dx, dy;
        queue<pair<int, int> > q;
        cin>>sx>>sy>>dx>>dy;
        if(sx<1 || dx<1 || sy>n || dy>n || grid[dx-1][dy-1]==0 || grid[sx-1][sy-1]==0 ){cout<<-1<<endl; continue;}
        cost_grid[sx-1][sy-1]=0;
        q.push(make_pair(sx-1, sy-1));
        grid[sx-1][sy-1]=2;
        int mx[] = {0, -1, 0, 1};
        int my[] = {-1, 0, 1, 0};
        bool found = false;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==dx-1 && y==dy-1){
                cout<<cost_grid[x][y]<<endl;
                found=true;
                break;
            }
            for(int i=0; i<4; i++){
                int nx = x+mx[i];
                int ny = y+my[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1){
                    if(nx!=x){
                        cost_grid[nx][ny]=cost_grid[x][y]+1;
                        grid[nx][ny]=2;
                        q.push(make_pair(nx, ny));
                    }
                    else{
                        cost_grid[nx][ny]=cost_grid[x][y];
                        grid[nx][ny]=2;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        if(!found)cout<<-1<<endl;



    }
}