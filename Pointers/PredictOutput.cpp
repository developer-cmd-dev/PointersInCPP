#include<bits/stdc++.h>
using namespace std;


int main(){
    int a=56;
    int *ptr = &a;
    int **ptr2 = &ptr;

    cout<<*ptr<<endl; // 56
    cout<<**ptr2<<endl; //56
    cout<<ptr<<endl; // address of a
    cout<<*ptr2<<endl; // address of a


    
    


    return 0;
}