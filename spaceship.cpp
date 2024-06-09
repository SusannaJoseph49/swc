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
int n;
void updateMatrix(int row, int col, vector<vector<int> > &grid){
    if(row<0) return;
    int upperLimit = max(0, row-4);
    for(int i=row;i>=upperLimit;i--){
        for(int j=0; j<=4; j++){
            if(grid[i][j]==2){
                grid[i][j]=0;
            }
        }
    }

}
int solve(int row, int col, vector<vector<int> > &grid, int bombs){
    if(row<=0 || col<=0 || row>n || col>=5) return 0;
    int ans = 0;

    //up
    if(grid[row-1][col]==1 && row>0){
        ans=max(ans, 1+solve(row-1, col, grid, bombs));
    }
    else if(grid[row-1][col]==0 && row>0){
        ans=max(ans, solve(row-1, col, grid, bombs));
    }


    //left
    if(grid[row-1][col-1]==1 && row>0 && col>0){
        ans=max(ans,1+solve(row-1, col-1, grid, bombs));
    }
    else if(grid[row-1][col-1]==0 && row>0 && col>0){
        ans=max(ans,solve(row-1, col-1, grid, bombs));
    }

    
    //right
    if(grid[row-1][col+1]==1 && row>0 && col>0){
        ans=max(ans,1+solve(row-1, col+1, grid, bombs));
    }
    else if(grid[row-1][col+1]==0 && row>0 && col>0){
        ans=max(ans,solve(row-1, col+1, grid, bombs));
    }
    //bomb case
    if(ans==0 && bombs>0){
        updateMatrix(row, col, grid);
        ans=max(ans, solve(row, col, grid, bombs-1));
    }
    return ans;


}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        vector<vector<int> > grid(n, vector<int>(5));
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                cin>>grid[i][j];
            }
        }
        cout<<solve(n, 2, grid, 1);
    }
    return 0;

}