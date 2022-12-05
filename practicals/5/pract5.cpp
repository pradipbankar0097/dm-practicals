#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    vector<double> p;
    vector<double> q;
    
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        p.push_back(val);
    }
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        q.push_back(val);
    }
    
    //Euclidean Distance represents the shortest distance between two points.
    
    double eculidean = 0;
    for(int i=0; i<n; i++){
        eculidean += pow((p[i] - q[i]),2);
    }
    
    eculidean = sqrt(eculidean);
    cout << "Euclidean Distance = " << eculidean << endl;
    
    
    //Manhattan Distance is the sum of absolute differences between points across all the dimensions.
    double manhattan = 0;
    for(int i=0; i<n; i++){
        manhattan += abs(p[i]-q[i]);
    }
    cout << "Manhattan Distance = " << manhattan << endl;
    
    // Minkowski Distance is the generalized form of Euclidean and Manhattan Distance.
    //using norm  = 3;
    double minikowski = 0;
    int norm = 3;
    for(int i=0; i<n; i++){
        minikowski += pow(abs(p[i]-q[i]),norm);
    }
    minikowski = pow(minikowski,1.0/norm);
    
    cout << "Minkowski Distance = " << minikowski << endl;
    
    
   return 0;
    
}


