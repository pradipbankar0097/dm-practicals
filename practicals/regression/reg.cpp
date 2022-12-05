#include <bits/stdc++.h>
using namespace std;
int main()
{    
    int n;
    cout<<"Enter the number of values to be calculated: "<<endl;
    cin>>n;
    int x[n],y[n];
    cout<<"Enter x values: "<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i];
    cout<<"Enter y values: "<<endl;
    for(int i=0;i<n;i++)
        cin>>y[i];
    int sx=accumulate(x,x+n,0);
    int sy=accumulate(y,y+n,0);
    int xs[n];
    int sum=0,sumxy=0;
    for(int i=0;i<n;i++)
    {        
        sum += x[i]*x[i];
        sumxy += x[i]*y[i];    
    }
    cout<<"\nSummation of x: "<<sx<<"\nSummation of y:  "<<sy<<"\nSummation of x^2: "<<sum<<"\nSummation of xy: "<<sumxy;  
    float b1 = (n*sumxy-sx*sy)/(float)(n*sum - sx*sx);
    float b0 = (sy-b1*sx)/(float)n;     
    cout<<"\n\nThe final equation of regression is: "<<b1<<" + "<<b0<<"x\n";    
    return 0;
}