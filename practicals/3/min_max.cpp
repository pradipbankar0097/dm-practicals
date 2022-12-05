#include<bits/stdc++.h>
#include "../1/mean.h"
#define endl '\n'
using namespace std;

vector<float> min_max(vector<float> &arr,int nmin,int nmax){
    int n= arr.size();
    vector<float> res(n);
    float mn,mx;
    mn = *min_element(arr.begin(),arr.end());
    mx = *max_element(arr.begin(),arr.end());
    for (int i = 0; i < n; i++)
    {
        res[i] = (nmax-nmin)*(arr[i]-mn)/(mx-mn)-(nmin);
    }
    return res;
}

vector<float> z_score(vector<float> arr,float mu,float sigma){
    int n = arr.size();
    vector<float> res(n);
    for(int i=0;i<n;i++){
        res[i] = (arr[i]-mu)/(sigma);
    }
    return res;
}

vector<float> decimal_normal(vector<float> &arr){
    int n = arr.size();
    vector<float> res(n);
    int div = 1;
    int mx= *max_element(arr.begin(),arr.end());
    while(mx){
        div*=10;
        mx/=10;
    }

    for(int i=0;i<n;i++){
        res[i] = arr[i]/float(div);
    }
    return res;
}

void akk(){
    int n;
    cin>>n;
    
    vector<float> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int nmin,nmax;
    cin>>nmin>>nmax;

    vector<float> new_min_max_normal = min_max(arr,nmin,nmax);

    cout<<"MinMax Normalization : "<<endl;
    for(int i=0;i<n;i++){
        cout<<new_min_max_normal[i]<<' ';
    }
    cout<<endl<<endl;
    
    int copy_arr[n];
    for(int i=0;i<n;i++){
        copy_arr[i] = arr[i];
    }

    float mu = mean(copy_arr,n);
    float sigma = sd(copy_arr,n);
    vector<float> new_z_score_normal = z_score(arr,mu,sigma);
    
    cout<<"Z-Score Normalization : "<<endl;
    for(auto &i:new_z_score_normal){
        cout<<i<<' ';
    }
    cout<<endl<<endl;

    cout<<"Decimal Normalization : "<<endl;
    vector<float> new_decimal_normal = decimal_normal(arr);
    for(auto &i:new_decimal_normal){
        cout<<i<<' ';
    }
    cout<<endl<<endl;
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