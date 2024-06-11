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

int grid[100][100];
int ans[100][100];
int value = -100;
int N;
bool isValid(int r, int c){
    if((grid[r][c]==2 || grid[r][c]==0) && r<N && c<N && r>=0 && c>=0) return true;
    else return false;
}
void solve(int r, int c, int diamonds){
    if(r==N-1 && c==N-1){
        if(diamonds>value){
            value=diamonds;
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    ans[i][j]=grid[i][j];
                }
            }
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};

    for(int i=0; i<4; i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(isValid(nr, nc)){
            int check;
            if(grid[nr][nc]==2) check=1;
            else if(grid[nr][nc]==0) check=0;

            grid[nr][nc]=3;
            solve(nr, nc, diamonds+check);

            if(check==1) grid[nr][nc]=2;
            else if(check==0) grid[nr][nc]=0;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                grid[i][j]=0;
                ans[i][j]=0;
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>grid[i][j];
            }
        }
        value=-100;
        grid[0][0]=3;
        solve(0, 0, 0);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<value<<endl;
    }
}