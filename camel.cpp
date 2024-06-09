#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
int globalAns = INT_MAX;
void solve(vector<int> &camel_cost, vector<int> &vis, bool left_to_right, int ans, int camels_taken, int n){
    if(ans>globalAns) return;
    if(camels_taken==n){
        globalAns=min(ans, globalAns);
    }
    if(left_to_right){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(vis[i]==0 && vis[j]==0){
                    vis[i]=1;
                    vis[j]=1;
                    int cost_max = max(camel_cost[i], camel_cost[j]);
                    solve(camel_cost, vis, !left_to_right, ans+cost_max, camels_taken+2, n);
                    vis[i]=0;
                    vis[j]=0;
                }
            }
        }
    }
    else{
        for(int i=0; i<n; i++){
            if(vis[i]==1){
                vis[i]=0;
                solve(camel_cost, vis, !left_to_right, ans+camel_cost[i], camels_taken-1, n);
                vis[i]=1;
            }
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        globalAns=INT_MAX;
        vector<int> camel_cost(n, 0);
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) cin>>camel_cost[i];
        solve(camel_cost, vis, true, 0, 0, n);
        cout<<globalAns<<endl;
    }
}