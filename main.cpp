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
    // Read the 2n x 2n grid (unused in this heuristic baseline).
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){int x; cin>>x;}
    }
    // Heuristic: output a bounded, cycling control pattern to explore space while keeping velocity bounded.
    // Limit the number of operations to avoid excessive I/O while ensuring enough controls: m >= 16n^2.
    long long t = min<long long>(m, 20LL * n * n);
    const string pat = "ABCDEEDCBA"; // net zero horizontal delta over a cycle
    for(long long i=0;i<t;i++) cout << pat[i % pat.size()] << '\n';
    return 0;
}
