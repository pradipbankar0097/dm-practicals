#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

float mean(int l[],int u[],int f[],int n){
    float fx[n];
    int N = accumulate(f,f+n,0);
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        float x = float(l[i]+u[i])/2.0f;
        fx[i] = x*float(f[i]);
        sum+=fx[i];
    }
    return sum/N;
}

float median(int l[],int u[],int f[],int n){
    int cf[n];
    cf[0] = f[0];
    for(int i=1;i<n;i++){
        cf[i] = cf[i-1]+f[i];
    }
    float nb2 = float(cf[n-1])/2.0f;
    int m_class_index=0;
    while(cf[m_class_index]<nb2){
        m_class_index++;
    }
    float Lm = l[m_class_index];
    float fm = f[m_class_index];
    float F = cf[m_class_index-1];
    float ans = Lm + ((nb2-F)/fm)*(l[1]-l[0]);
    return ans;
}

void akk(){
    int n;
    cin>>n;
    int l[n],u[n],f[n];
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        l[i] = a;
        u[i] = b;
        f[i] = c;
    }
    cout<<mean(l,u,f,n)<<endl;
    cout<<median(l,u,f,n)<<endl;
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