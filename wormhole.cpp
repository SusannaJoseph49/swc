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
//initialize n and ans globally
//initialize ans as INT_MAX globally and inside each test case also initialize it as INT_MAX

///IMPORTANT///
///struct wormhole
///struct point
///int distance(point a, point b)

//void solve(point src, point dest, vector<wormhole> &wormholedata, vector<int> &vis, int curr_cost )
//////int temp = curr_cost+distance(src, dest);
//////ans=min(ans, temp);
////// for(int i=0; i<wormholedata.size(); i++){
//         if(vis[i]==0){
///                  make into vis
/// solve for both entries
//// make not visited

int n;
int ans = INT_MAX;

struct wormhole{
    int sx;
    int sy;
    int dx;
    int dy;
    int cost_wh;
};
struct point{
    int x;
    int y;
};
int distance(point a, point b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}
void solve(point src, point dest, vector<wormhole> &wormholedata, vector<int> &vis, int curr_cost ){
    int temp = curr_cost+distance(src, dest);
    ans=min(ans, temp);
    for(int i=0; i<wormholedata.size(); i++){
        if(vis[i]==0){
            vis[i]=1;
            point wormhole_entry_1, wormhole_entry_2;
            wormhole_entry_1.x = wormholedata[i].sx;
            wormhole_entry_1.y = wormholedata[i].sy;
            wormhole_entry_2.x = wormholedata[i].dx;
            wormhole_entry_2.y = wormholedata[i].dy;
            int cost_entry1 = distance(src, wormhole_entry_1)+wormholedata[i].cost_wh;
            solve(wormhole_entry_2, dest, wormholedata, vis, curr_cost+cost_entry1);
            int cost_entry2 = distance(src, wormhole_entry_2)+wormholedata[i].cost_wh;
            solve(wormhole_entry_1, dest, wormholedata, vis, curr_cost+cost_entry2);
            vis[i]=0;
        }
    }

}
int main(){
    int T;
    cin>>T;
    while(T--){
        ans=INT_MAX;
        cin>>n;
        vector<wormhole> wormholedata(n);
        point source, destination;
        cin>>source.x>>source.y>>destination.x>>destination.y;
        for(int i=0; i<n; i++){
            cin>>wormholedata[i].sx>>wormholedata[i].sy>>wormholedata[i].dx>>wormholedata[i].dy>>wormholedata[i].cost_wh;
        }
        vector<int> vis(10000, 0);
        solve(source, destination, wormholedata, vis, 0);
        cout<<ans<<endl;

    }

}