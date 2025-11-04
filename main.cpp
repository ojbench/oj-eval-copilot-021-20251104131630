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

    auto emit = [](int d){ static const char mp[5]={'A','B','C','D','E'}; cout << mp[d+2] << '\n'; };
    long long vx = 0;
    long long t = m;

    // Phase lengths
    long long T1 = t/3, T2 = t/3, T3 = t - T1 - T2;

    // Phase 1: deterministic sweep towards a sequence of targets to scan slopes
    {
        vector<int> targets;
        int V = max(8, n); // wider coverage early
        for(int a=1;a<=V;a++) { targets.push_back(a); targets.push_back(-a); }
        size_t ptr = 0;
        for(long long i=0;i<T1;i++){
            if(ptr>=targets.size()) ptr=0;
            int target = targets[ptr];
            long long need = target - vx;
            int d = 0;
            if(llabs(need)>=2) d = (need>0? 2 : -2);
            else if(llabs(need)==1) d = (need>0? 1 : -1);
            else { d = 0; ptr++; }
            vx += d; emit(d);
            if(llabs(vx - target)<=1) ptr++;
        }
    }

    // Phase 2: randomized bounded walk to break symmetries
    {
        uint64_t rng = (uint64_t)k * 1469598103934665603ULL ^ (uint64_t)n * 1099511628211ULL ^ (uint64_t)m;
        auto step = [&](){ rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17; return rng; };
        int K = max(6, n*2/3);
        for(long long i=0;i<T2;i++){
            int d = (int)(step()%5) - 2; // -2..2
            if(vx > K) d = (d>0? -d : d); // bias back
            if(vx < -K) d = (d<0? -d : d);
            vx += d; emit(d);
        }
    }

    // Phase 3: high-slope bursts with coasts
    {
        int HV = max(12, n*4/3);
        int dir = (k&1)?1:-1;
        for(long long i=0;i<T3;i++){
            int target = dir>0? HV : -HV;
            int d = 0; long long need = target - vx;
            if(llabs(need)>=2) d = (need>0? 2 : -2);
            else if(llabs(need)==1) d = (need>0? 1 : -1);
            else d = 0;
            // coast every 7 steps
            if(i%7==0) d = 0;
            vx += d; emit(d);
            if(llabs(vx - target)<=1) dir = -dir;
        }
    }

    return 0;
}
