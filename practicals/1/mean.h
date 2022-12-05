#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

float mean(int arr[],int n){
    long long sum = 0ll;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return (1.0f*sum/(n));
}

float median(int arr[],int n){
    sort(arr,arr+n);
    if(n%2){
        return *(arr+n/2);
    }
    return (1.0f*((arr[n/2]+arr[n/2]-1)))/2.0f;
}

int mode(int arr[],int n){
    map<int,int> cnt;
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }
    pair<int,int> ans = {0,0};
    for(auto i:cnt){
        if(i.second>ans.second){
            ans = i;
        }
    }
    return ans.first;
}

float variance(int arr[],int n){
    float diff[n];
    float sum = 0;
    float mean_val = mean(arr,n);
    for(int i=0;i<n;i++){
        diff[i] = (mean_val-arr[i])*(mean_val-arr[i]);
        sum+=diff[i];
    }
    return sum/n;
}

float sd(int arr[],int n){
    float var = variance(arr,n);
    return sqrt(var);
}
