#include<iostream>
using namespace std;
class ninja{
   public:
       void print()
       {
        cout<<"derived print called"<<endl;
       }
       void give()
       {
        cout<<"derived give called"<<endl;
       }
};

class ninja: public {
   public:
       void print()
       {
        cout<<"derived print called"<<endl;
       }
       void give()
       {
        cout<<"derived give called"<<endl;
       }
};
int main()
{     




    return 0;
}