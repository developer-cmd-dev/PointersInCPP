#include<bits/stdc++.h>
using namespace std;


int main(){

    int a = 55;
    int* ptr = &a;
    int** ptr2 = &ptr;
    cout<<a<<" value of A"<<endl;
    *(ptr) = 88;
    cout<<a<<" Chaged Value of A using pointer"<<endl;
    
    string name = "Dev kumar";
    string* ptrName = &name;

    cout<<ptrName<<endl;
    






    return 0;


}