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
    // Read the 2n x 2n grid but we do not use it in this baseline.
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){int x; cin>>x;}
    }
    // Simple baseline: make the ball acquire small rightward velocity once.
    // Output one control: 'D' (vx += 1 to the right). Further bottom touches keep velocity unchanged.
    cout << 'D' << '\n';
    return 0;
}
