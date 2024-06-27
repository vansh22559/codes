#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


vector<int> kmp(string& s){
    int n = s.size();
    vector<int> kmpArr(n,0);
    for(int i = 1;i<n;i++){
        int j = kmpArr[i-1];
        if(s[i] == s[j]){
            kmpArr[i] = j+1;
        }
        else{
            while(j>0 && s[i]!=s[j]){
                j--;
                j = kmpArr[j];
            }
            if(s[i]==s[j]){
                kmpArr[i] = j+1;
            }
        }
    }
    return kmpArr;
}

void solve(){
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}