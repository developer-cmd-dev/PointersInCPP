#include<bits/stdc++.h>
using namespace std;


void changeA(int *a){
    *a = 88;
}

void changeAusingAlias(int &a){
    a=90;
}

int main(){

    int a =67;
    cout<<"Before changing A: "<<a<<endl;
    changeA(&a);
    cout<<"After changing A: "<<a<<endl;
    changeAusingAlias(a);
    cout<<"After changing A using Alias: "<<a<<endl;
  
    


    return 0;
}