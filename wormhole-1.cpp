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

struct wormhole{
    int sx, sy, dx, dy, cost_wh;
};
struct point{
    int x, y;
};
int ans = INT_MAX;
int dist(point x, point y){
    return abs(x.x-y.x)+abs(x.y-y.y);
}
void solve(point src, point dest, vector<wormhole> &wormholedata, vector<int>&vis, int curr_cost){
    int temp = curr_cost+dist(src, dest);
    ans=min(ans, temp);
    for(int i=0; i<wormholedata.size(); i++){
        if(vis[i]==0){
            vis[i]=1;
            point temp1, temp2;
            temp1.x = wormholedata[i].sx;
            temp1.y = wormholedata[i].sy;
            temp2.x = wormholedata[i].dx;
            temp2.y = wormholedata[i].dy;
            int value1 = curr_cost+dist(src, temp1)+wormholedata[i].cost_wh;
            solve(temp2, dest, wormholedata, vis, value1);
            int value2 = curr_cost+dist(src, temp2)+wormholedata[i].cost_wh;
            solve(temp1, dest, wormholedata, vis, value2);
            vis[i]=0;
        }
        
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int Sx, Sy, Dx, Dy;
        cin>>Sx>>Sy>>Dx>>Dy;
        point s, d;
        s.x=Sx;
        s.y=Sy;
        d.x=Dx;
        d.y=Dy;
        ans = INT_MAX;
        vector<wormhole> wormholedata(n);
        vector<int> vis(10000, 0);
        for(int i=0; i<n; i++){
            cin>>wormholedata[i].sx>>wormholedata[i].sy>>wormholedata[i].dx>>wormholedata[i].dy>>wormholedata[i].cost_wh;
        }
        solve(s, d, wormholedata, vis, 0);
        cout<<ans<<endl;
    }
}