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
    string s;
    cin>>s;
    int n = s.length();
    int freq = 1;
    string ans = "";
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]) freq++;
        else{
            ans=ans+s[i-1]+to_string(freq);
            freq=1;
        }

    }
    ans=ans+s[n-1]+to_string(freq);
    cout<<ans;
}