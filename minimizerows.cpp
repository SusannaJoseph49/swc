#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> heights(n, 0);
    for(int i=0; i<n; i++) cin>>heights[i];
    int ans=1;
    for(int i=1; i<n; i++){
        if(heights[i]<heights[i-1]){
            continue;
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;
}