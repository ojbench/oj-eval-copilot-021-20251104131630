#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,n,m,s; 
    if(!(cin>>k)) return 0; 
    if(!(cin>>n)) return 0; 
    if(!(cin>>m)) return 0; 
    if(!(cin>>s)) return 0; 
    for(int i=0;i<2*n;i++) for(int j=0;j<2*n;j++){int x; cin>>x; (void)x;}

    long long t = m;
    // Sawtooth target velocity sweeping across [-V,V]
    long long V = max(6, n*2/3); // moderate bound
    long long vx = 0;
    long long dir = (k%2? 1 : -1);
    auto emit = [](int d){ static const char mp[5]={'A','B','C','D','E'}; cout << mp[d+2] << '\n'; };

    // Mix in a deterministic cadence with occasional coasts
    for(long long i=0;i<t;i++){
        long long target = dir>0 ? V : -V;
        int d = 0;
        long long need = target - vx;
        if(abs(need) >= 2) d = (need>0? 2 : -2);
        else if(abs(need) == 1) d = (need>0? 1 : -1);
        else d = 0;
        // Insert periodic coasts every few steps to stabilize trajectories
        if((i % (max(10, n/5))) == 0) d = 0;
        vx += d;
        emit(d);
        // Flip direction when near target
        if(llabs(vx - target) <= 1) dir = -dir;
    }
    return 0;
}
