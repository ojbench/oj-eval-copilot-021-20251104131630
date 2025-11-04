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
    // Read the 2n x 2n grid (unused here).
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){int x; cin>>x;}
    }
    // Pseudo-random but bounded velocity adjustment sequence to diversify trajectories.
    long long t = m; // use full allowance
    long long K = max(8, n); // velocity bound heuristic
    long long vx = 0;
    uint64_t rng = (uint64_t)k * 1469598103934665603ULL ^ (uint64_t)n * 1099511628211ULL ^ (uint64_t)m;
    auto step = [&](){ rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17; return rng; };
    auto emit = [](int d){ static const char mp[5]={'A','B','C','D','E'}; cout << mp[d+2] << '\n'; };
    for(long long i=0;i<t;i++){
        // Bias to keep |vx| within K while adding randomness
        int deltas[5] = {-2,-1,0,1,2};
        int choice = (int)(step()%5);
        int d = deltas[choice];
        if(vx > K) d = (step()%2? -2: -1);
        else if(vx < -K) d = (step()%2? 2: 1);
        // Occasionally force stronger turns
        if((step() & 255) == 0){ d = (step()&1)? 2 : -2; }
        vx += d;
        // Soft clamp by nudging back next time; don't hard clip to preserve variability
        emit(d);
    }
    return 0;
}
