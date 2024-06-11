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
int n;

bool isValid(int r, int c){
    if(r<n  && r>=0 && c<5 && c>=0){
        return true;
    }
    else{
        return false;
    }
}
int solve(int r, int c, int power, int effect){
    if(r<0) return 0;
    int ans=0; int p=0;
    for(int i=-1; i<=1; i++){
        int x = r - 1;
        int y = c + i;
        if(isValid(x, y)){
            if(grid[x][y]==2){
                if(power==0 && effect>0){
                    p=solve(x, y, power, effect-1);
                }
                else if(power==1){
                    p=solve(x, y, power-1, 5);
                }
            }
            else if(grid[x][y]==1 || grid[x][y]==0){
                if(power==0){
                    p=solve(x, y, power, effect-1);
                }
                else{
                    p=solve(x, y, power, 5);
                }
            }
        }
        ans=max(ans, p);
    }
    if(grid[r][c]==1) ans++;
    return ans;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                grid[i][j]=0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                cin>>grid[i][j];
            }
        }
        cout<<solve(n, 2, 1, 0)<<endl;
    }
    return 0;
}