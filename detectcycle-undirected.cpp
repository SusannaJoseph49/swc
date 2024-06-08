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


//we keep node of parent vertex and current vertex
// from main we will always send -1 as the parent vertex
//bool detectCycle, takes curr vertes, parent vertex, adjMat and vis
//first we makr the incoming current vertex as vis[vertx]=1
//we iterate through all the edges and aee of edges with path present, ie adj[vertex][i]==1
//if path is present we check if the vertex i is visited or not, if not, we call bool detectCycle again with current vertex as i and parent as vertex
//if its visited and the index i is not equal to the parent vertx then we return true(its cyclic)
bool detectCycle(int vertex, int parentvertex, vector<vector<int> > &adjMat, vector<int> &vis){
    vis[vertex]=1;
    int N = adjMat.size();
    for(int i=0; i<N; i++){
        if(adjMat[i][vertex]==1){
            if(vis[i]==0){
                detectCycle(i, vertex, adjMat, vis);
            }
            else if(vis[i]==1 && i!=parentvertex){
                //cycle detected
                return true;
            }
        }
    }
    return false;
}
int main(){
    int N; cin>>N;
    vector<vector<int> > adjMat(N, vector<int> (N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>adjMat[i][j];
        }
    }
    vector<int> vis(N, 0);
    for(int i=0; i<N; i++){
        if(vis[i]==0){
            if(detectCycle(i, -1, adjMat, vis)){
                cout<<"cycle detected"<<endl;
                return 0;
            }
        }
    }
    cout<<"no cycle"<<endl;


}