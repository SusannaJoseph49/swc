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

//four globally initialized variable n, grid[100][100], ans[100][100], value=-100
//we define an isValid frunction also which checks for bounds. It should also havr conditions grid[x][y]==2 or grid[x][y]==0 (jewel or path)


//in solve function we take paramerets int r, int c, and int diamonds
//first we chek if we have reached the end of the matrix, i.e, r==n-1 and c==n-1
////BASE CONDITION
////we check if diamonds > value . If yes we change the value of value to diamonds and we put the grid matrix to the ans matrix

////We go through all the four directions of the current r, c
////We check if its a valid position
//////if its a valid position and grid[nx][ny]==0 we make check=>0
//////if its a valid position and grid[nx][ny]==2 we make check=>2
//////we mark nx ny as visited =>> grid[nx][ny]=3
///// recursive call solve(nx, ny, diamonds+check)
///// we reinitialize the grid[nx][ny] back based on check, if check=0 => grid[nx][ny]=0, check=1 => grid[nx][ny]=2



//main function , we take the input n (globally initialized)
// we take the grid input
//we mak grid[0][0]=3
//value=-100
//we call solve(0,0,0)

//cout value
//cout ans[][]

int n;
int grid[100][100];
int ans[100][100];
int value=-100;

bool isValid(int x, int y){
    if((grid[x][y]==0 || grid[x][y]==2) && x>=0 && y>=0 && x<n && y<n) return true;
    else return false;
}

void solve(int r, int c, int diamonds){
    if(r==n-1 && c==n-1){
        if(diamonds>value){
            value=diamonds;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    ans[i][j]=grid[i][j];
                }
            }
        }
    }

    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    for(int i=0; i<4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
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
    int T;
    cin>>T;
    while(T--){
       cin>>n;
       for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
       }

       grid[0][0]=3;
       value=-100;
       solve(0,0,0);

       for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
       }
       cout<<value<<endl;
    }
}