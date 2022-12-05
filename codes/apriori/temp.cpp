#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void akk(){
    int x = 5;
    cout<< x++ + ++x <<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin>> tt;
    while(tt--){
        akk();
    }
    return 0;
}