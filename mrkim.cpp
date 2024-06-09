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
//points are an array of type pair. It has all the delivery points. The first point is the office and the last one is home
//we have a vis array of size n+2, (n is the number of delivery locations)
//dist function finds the manhattan distance when two indexes are given


//we have a solve function with parameters -->> index, deliverynos, points, vis, cost, n
//BASE CONDITION
//if deliverynos==n retrun cost+=dist(index, n+1, points)


//initialize ans as INT_MAX
//go through all the points in the points array (from indices 1 to n)
//if its not vis, vis[i]==0
//////make vis as 1
/////update ans as ans=min(ans, solve(i, deliverynos+1, adjMat, vis, cost+dist(index, i), n))
///// make vis back to 0
int dist(int i, int j, vector<pair<int, int> > &points) {
    int x1 = points[i].first, x2 = points[j].first;
    int y1 = points[i].second, y2 = points[j].second;
    return abs(x1 - x2) + abs(y1 - y2);
}
int solve(int index, int deliverynos, vector<pair<int, int> > &points, vector<int> &vis, int cost, int &n ){
    if(deliverynos==n){
        return cost=cost+dist(index, n+1, points);
    }
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            vis[i]=1;
            ans=min(ans, solve(i, deliverynos+1, points, vis, cost+dist(index, i, points), n));
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
        int sx, sy, dx, dy;
        cin>>sx>>sy>>dx>>dy;
        vector<pair<int, int> > points;
        points.push_back(make_pair(sx, sy));
        for(int i=0; i<n; i++){
            int xo, yo;
            cin>>xo>>yo;
            points.push_back(make_pair(xo, yo));
        }
        points.push_back(make_pair(dx, dy));
        vector<int> vis(n+2, 0);
        vis[0]=1;
        int res = solve(0, 0, points, vis, 0, n);
        cout<<res<<endl;

    }
}