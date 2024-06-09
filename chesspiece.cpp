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

//we are given just the dimensions of the chess board(NxM), the starting positiond (R,C), and final position (S,K)
//queue of type  ->> queue<pair<pair<int, int>, int> > q. We push ((R-1, C-1),0) into the wueue first with vis[R-1][C-1]=1;
//we make a visited vector of NxM to node the visited values (make it 1 when we encounter it inside the 1 to 4 loop)
//to the check condition for if they have reced target outside the 1 to 4 loop

int main(){
    int N, M, R, C, S, K; 
    cin>>N>>M;
    cin>>R>>C>>S>>K;
    if(R < 1 || R > N || C < 1 || C > M || S < 1 || S > N || K < 1 || K > M){
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int> > vis(N, vector<int>(M, 0));
    int mv[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    vis[R-1][C-1]=1;
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(R-1, C-1), 0));
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int level = q.front().second;
        q.pop();
        if(x==S-1 && y==K-1) {
            cout<<level<<endl; return 0;
        }
        for(int i=0; i<8; i++){
            int tx = x + mv[i][0];
            int ty = y + mv[i][1];
            if(tx>=0 && ty>=0 && tx<N && ty<M && vis[tx][ty]==0){
                vis[tx][ty]=1;
                q.push(make_pair(make_pair(tx, ty), level+1));
            }

        }

    }
    cout<<-1<<endl;

}