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


//No use of a visited array. only a color array INITIALIZED TO -1
//use of a flag variabe initialized to true
bool isBipartite(int index, vector<vector<int> > &adjMat, vector<int> &color){
    int n = adjMat.size();
    bool flag = true;
    for(int i=0; i<n; i++){
        //to check if path exists
        if(adjMat[index][i]==1){
            //if color is no set for the index we are going for
            if(color[i]==-1){
                //flip the colour of the INDEX edge
                color[i]=1-color[index];
                flag=flag&isBipartite(i, adjMat, color);
            }
            else if(color[i]==color[index]){
                return false;
            }
        }
    }
    return flag;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int> > adjMat (n, vector<int>(n, 0));
    vector<int> color(n, -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adjMat[i][j];
        }
    }
    for(int i=0; i<n; i++){
        if(color[i]==-1){
            color[i]=0;
            // if not bipartite then output -1; and returm 0;
            if(!isBipartite(i, adjMat, color)){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(color[i]==0){
            cout<<i<<" ";
        }
    }
}