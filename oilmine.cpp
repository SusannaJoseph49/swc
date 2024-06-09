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
//companies and mines are initialized outside the loop
//int ans = INT_MAX; iss initialized outside the loop
//the solve is called inside a loo
//solve(i, oilmins, vis, INT_MAX, INT MIN, 0, 0, ans); =>>> solve(i, oilmins, vis, INT_MAX, INT MIN, sum, nodes, ans);
/////SOLVE FUNCTION
/////check if visited, if vis[i]==1 =>> int newMin and newMax, if(nodes==companies-1){ans=min(ans, newMax-newMax); return;}
//////////vis[i]=1, 
//////////j=(i+1)%mines, 
//////////solve(j, oilmines, vis, minV, maxV, sum+oilmines[i], nodes, ans), 
//////////newMin, 
//////////newMax, 
//////////solve(j, oilmines, vis, newMin, newMax, oilmines[i], nodes+1, ans)
/////////vis[i]=0
/////////return;
int companies, mines;
void solve(int i, vector<int> &oilmines, vector<int> &vis, int minV, int maxV, int sum, int nodes, int &ans ){
    if(vis[i]==1){
        int newMin = min(sum, minV);
        int newMax = max(sum, maxV);
        if(nodes==companies-1){
            ans=min(ans, newMax-newMin);
        }
        return;
    }
    vis[i]=1;
    int j = (i+1)%mines;
    solve(j, oilmines, vis, minV, maxV, sum+oilmines[i], nodes, ans);
    int newMin = min(sum, minV);
    int newMax = max(sum, maxV);
    solve(j, oilmines, vis, newMin, newMax, oilmines[i], nodes+1, ans);
    vis[i]=0;
    return ;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>companies>>mines;
        vector<int> oilmines(mines, 0);
        vector<int> vis(mines, 0);
        for(int i=0; i<mines;i++) cin>>oilmines[i];
        int ans = INT_MAX;
        for(int i=0; i<mines; i++){
            solve(i, oilmines, vis, INT_MAX, INT_MIN, 0, 0, ans);
        }
        cout<<ans<<endl;

    }
}