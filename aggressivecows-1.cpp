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
bool isPossible(int target, vector<int> &index, int cows){
    int currPos = index[0];
    int currCows = 1;
    for(int i=1; i<index.size(); i++){
       if(index[i]-currPos>=target){
        currCows++;
        currPos=index[i];
       }
       else continue;
    }
    if(currCows>=cows) return true;
    else return false;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n, cows;
        cin>>n>>cows;
        vector<int> index(n, 0);
        for(int i=0; i<n; i++) cin>>index[i];
        sort(index.begin(), index.end());
        int low=1;
        int high=index[n-1]-index[0];
        while(low<=high){
            int mid=(high+low)/2;
            if(isPossible(mid, index, cows )){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<high<<endl;
    }
    return 0;
}