#include<iostream>
#include<vector>
using namespace std;

class A{
public:
    A(){
        cout<<"A"<<endl;
    }
};

class C{
public:
    C(){
        cout<<"C"<<endl;
    }
};

class B:public A{
public:
    C c;
    B(){
        cout<<"B"<<endl;
    }
};


int main(){
    // vector<int> a;
    // a.reserve(10); //malloc but not memset
    // cout<<a[0];

    // char* const p1 = "12368326483649";
    // char p2[5] = "123";
    // cout<<sizeof(p1)<<endl;
    // cout<<sizeof(p2)<<endl;
    // cout<<sizeof(p2[0])<<endl;
    // cout<<sizeof(p2+1)<<endl;

    // string str = "5453646";
    // cout<<sizeof(str);
    // int a=1;
    // int& b = a; 
    // int* c = &a;
    // cout<<sizeof(b)<<endl; //4
    // cout<<sizeof(c); //8

    // int a[2][2] = {{1,2},{3,4}};
    // cout<<**(a+1);
    B b;
    return 0;
}