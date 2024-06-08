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

//exactly the same as undirected but inspead of maintaing the paraent we maintain a pathvis array
//in bool detectcCycle we first make pth vis[vertex] and pathvis[vertex] as 1
//we visit all the connected vertes and wee if its vis[i] is true or false ,if its not visited then do the dfs call. if it comes out as true return true
//if its visited and then pathvis[i] is not visited return true


////before existing loop and returning false make pathvis[vertex] as 0
bool detectCycle(int vertex, vector<vector<int> > &adjMat, vector<int> &vis, vector<int> &pathvis){
    vis[vertex]=1;
    pathvis[vertex]=1;
    for(int i=0; i<adjMat.size();i++){
        if(adjMat[vertex][i]==1){
            if(vis[i]==0){
                if(detectCycle(i, adjMat, vis, pathvis)==true) return true;
            }
            else if(vis[i]==1 && pathvis[i]==0){
                return true;
            }
        }
    }
    pathvis[vertex]=0;
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
    vector<int> pathvis(N, 0);
    or(int i=0; i<N; i++){
        if(vis[i]==0){
            if(detectCycle(i, adjMat, vis, pathvis)){
                cout<<"cycle detected"<<endl;
                return 0;
            }
        }
    }
    cout<<"no cycle"<<endl;
}