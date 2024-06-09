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
    int n,m,k;cin>>n>>m>>k;
    map<string,int> mp;
    for(int i=0; i<n;i++){
        string s = "";
        for(int j=0; j<m; j++){
            int x;cin>>x;
            s=s+to_string(x);

        }
        if(mp.find(s)!=mp.end()){
            mp[s]++;
        }
        else{
            mp.insert(std::make_pair(s, 1));
        }
    }
    int ans =0;
    for (auto i = mp.begin(); i != mp.end(); i++){
        string s = i->first;
        int number = i->second;
        int zero = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0') zero++;
        }
        // cout<<zero<<endl;
        if((k-zero)%2==0 && zero<=k){
            ans=max(ans, number);
        }
    }
        cout <<ans<< endl;
}