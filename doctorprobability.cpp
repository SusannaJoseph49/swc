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

//go for 1 based indexing
//// adjMat (of double type) nodes+1 x nodes+1, initialised to 0.0
//// ans vector (of type double) size node+1, initialised to 0.0
////solve(index, &adjMat, nodes, time, prob, &ans)
//////base condition (time<=0) => ans[index]+=prob; return
////// iterate through all nodes and take nodes with adjMat!=0.0  
/////////prob=prob*adjMat[index][i];
/////////solve(i, adjMat, nodes, time-10, prob, ans);
/////////prob=prob/adjMat[index][i];
void solve(int index, vector<vector<double> > &adjMat, int nodes, int time, double prob, vector<double> &ans ){
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
    int T;
    cin>>T;
    while(T--){
        int nodes, edges, time;
        cin>>nodes>>edges>>time;
        vector<vector<double> > adjMat(nodes+1, vector<double>(nodes+1, 0.0));
        vector<double> ans(nodes+1, 0.0);
        for(int i=1; i<=edges; i++){
           int start, end;
           double probability;
           cin>>start>>end>>probability;
           adjMat[start][end]=probability;
        }
        solve(1, adjMat, nodes, time, 1.0, ans);
        double finalprob=0.0;
        int finaldest;
        for(int i=1; i<=nodes; i++){
            if(ans[i]>finalprob){
                finalprob=ans[i];
                finaldest=i;
            }
        }
        cout<<finaldest<<" "<<finalprob<<endl;
    }



}