#include<iostream>
using namespace std;

class A{
private:
    char* p;
public:
    A(){
        p = (char *)malloc(100);
    }
    ~A(){
        cout<<"~A"<<endl;
        if(p){
            cout<<"delete"<<endl;
            delete p;
        }
    }
};

int main(){
    A a;
    A b = a;//默认浅拷贝
    return 0;
}