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
void solve(int index, vector<vector<double> > &adjMat, int nodes, int time, double prob, vector<double> &ans){
    if(time<=0){
        ans[index]=ans[index]+prob;
        return;
    }
    for(int i=1; i<=nodes; i++){
        if(adjMat[index][i]!=0.0){
            prob=prob*adjMat[index][i];
            solve(i, adjMat, nodes, time-10, prob, ans);
            prob=prob/adjMat[index][i];
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int nodes, edges, time;
        cin>>nodes>>edges>>time;
        vector<vector<double> > adjMat(nodes+1, vector<double>(nodes+1, 0.0));
        vector<double> ans(nodes+1, 0.0);
        for(int i=1; i<=edges; i++){
            int x, y;
            double probabilty;
            cin>>x>>y>>probabilty;
            adjMat[x][y]=probabilty;
        }

        solve(1, adjMat, nodes, time, 1.0, ans);

        int finalDest = 0;
        double finalProb = 0.0;
        for(int i=1; i<=nodes; i++){
            if(ans[i]>=finalProb){finalProb=ans[i]; finalDest=i;}
        }
        cout<<finalDest<<" "<<finalProb<<endl;
    }
    return 0;
}