#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct configuration{
    int D;
    int E;
    int F;
    int SPi;
};
configuration m[10];
int D, E, F, d, e, config;
int ans = 0;
void solve(int index, int countconfig, int D, int E, int F, int cost){
    if(countconfig==3 || index==config-1){
        cost=cost+(D*d+E*e);
        if(cost>ans) ans=cost;
        return;
    }
    solve(index+1, countconfig, D, E, F, cost);
    int i=1;
    while(true){
        if(D-m[i].D*i>=0 && E-m[i].E*i>=0 && F-m[i].F>=0){
            solve(index+1, countconfig+1, D-m[i].D*i, E-m[i].E*i, F-m[i].F, cost+m[i].SPi*i);
            i++;
        }
        else{
            continue;
        }
    }
    return;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>D>>E>>F>>d>>e;
        cin>>config;
        ans=0;
        for(int i=0; i<10; i++){
            m[i].D=0; m[i].E=0; m[i].F=0; m[i].SPi=0;
        }
        for(int i=0; i<config; i++){
            cin>>m[i].D>>m[i].E>>m[i].F>>m[i].SPi;
        }
        solve(0, 0, D, E, F, 0);
        cout<<ans<<endl;

    }
}