#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// The Z-function for this string is an array of length n where the  
// i-th element is equal to the greatest number of characters starting from the position  
// i that coincide with the first characters of string s .

vector<int> z_function(string s) {
    int n = s.size();
    int l = 0 , r = 0;
    vector<int> z(n,0);
    for(int i = 1;i<n;i++){
        if(i < r){
            z[i] = min(r-i,z[i-l]);
        }
        while(i+z[i]<n && s[i+z[i]] == s[z[i]]){
            z[i]++;
        }
        if(i+z[i] > r){
            r = i+z[i];
            l = i;
        }
    }
    return z;
}

void solve(){
    string s = "aaabcde";
    vector<int> z = z_function(s);
    for(auto i:z){
        cout<<i<<" ";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
