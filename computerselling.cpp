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
//GLOBAL INITIALIZATIONS ==>> struct configuration (D,E,F,SPi),  configuration array m[10], int D, E, F, d, e, config
//GLOBAL INITIALIZATIONS ==>> int ans = 0; (VERY IMPORTANT) (We initialize ans to zero intide every test case also)

//solve(0,0,D,E,F,0) => solve(index, countconfig, D, E, F, cost)

struct configuration {
    int D; int E; int F; int SPi;
};
configuration m[10];
int D, E, F, d, e, config;
int ans=0;

void solve(int index, int countconfig, int D, int E, int F, int cost){
    if(index>=config || countconfig==3){
        cost=cost+(D*d + E*e);
        if(cost>ans){
            ans=cost;
        }
        return;
    }

    solve(index+1, countconfig, D, E, F, cost);

    int i = 1;

    while(true){
        if(D-m[index].D*i>=0 && E-m[index].E*i>=0 && F-m[index].F*i>=0 ){
            solve(index+1, countconfig+1, D-m[index].D*i, E-m[index].E*i, F-m[index].F*i, cost+m[index].SPi*i);
            i++;
        }
        else{
            break;
        }
    }

    return;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        //inside every iteration initialize ans to zero. basically for every new test case
        ans=0;
        cin>>D>>E>>F>>d>>e;
        cin>>config;
        for(int i=0; i<config; i++){
            cin>>m[i].D>>m[i].E>>m[i].F>>m[i].SPi;
        }
        solve(0, 0, D, E, F, 0);

        cout<<ans<<endl;


    }
}