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
//pretty much same as mrkim
//instead of dist function we have adjMat
//When we check for not visited and countruesvis==n-1 we add another condition if adjMat!=0
int solve(int index, int countriesvis, vector<vector<int> > &adjMat, vector<int> &vis, int cost, int &n ){
    if(countriesvis==n-1 && adjMat[index][0]!=0){
        return cost=cost+adjMat[index][0];
    }
    int ans = INT_MAX;
    for(int i=1; i<n; i++){
        if(vis[i]==0 && adjMat[index][i]!=0){
            vis[i]=1;
            ans=min(ans, solve(i, countriesvis+1, adjMat, vis, cost+adjMat[index][i], n));
            vis[i]=0;
        }
    }
    return ans;
    
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<vector<int> > adjMat(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>adjMat[i][j];
            }
        }
        vector<int> vis(n, 0);
        vis[0]=1;
        int res = solve(0, 0, adjMat, vis, 0, n);
        cout<<res<<endl;

    }
}
