#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

struct Manacher{
    vector<int> p;
    void build(string &s){
        string t;
        for(auto i:s){
            t += string("#")+i;
        }t.push_back('#');
        run_manacher(t);
    }
    void run_manacher(string& t){
        p.resize(t.size(),1);
        int l = 1, r = 1;
        for(int i = 1;i<t.size();i++){
            if(l+r-i >= 0 && l+r-i < p.size()){
                p[i] = max(0ll,min(p[l+r-i],r-i));
            }
            while(i-p[i] >=0 && i+p[i] < t.size() && t[i-p[i]] == t[i+p[i]] ){
                p[i]++;
            }
            if(i+p[i] > r){
                //update the bounding box then
                r = i+p[i];
                l = i-p[i];
            }
        }

    }
    int getLongestPallin(int centre,bool odd){
        int pos = (2*centre)+1+(!odd);
        return p[pos]-1;
    }
    bool isPallin(int a,int b){
        int cen = (a+b)/2;
        return (getLongestPallin(cen,(b-a+1)&1) >= (b-a+1));
    }
};

void solve(){
    string s = "abbad"   ;
    Manacher m;
    m.build(s);
    cout<< m.isPallin(0,3);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
