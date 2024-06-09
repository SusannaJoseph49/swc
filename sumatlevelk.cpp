#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
int main(){
    int k;
    string s;
    cin>>s>>k;
    int n = s.length();
    int ans=0;
    int level=-1;
    for(int i=0; i<n; i++){
        if(s[i]=='(') level++;
        else if(s[i]==')') level--;
        else{
            if(level==k) ans=ans+(s[i]-'0');
        }
    }
    cout<<ans;


}