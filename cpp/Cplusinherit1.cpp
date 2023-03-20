#include<iostream>
#include<queue>
using namespace std;
class Animal {
public:
    int a, b;
    Animal(){
        cout<<"Animal"<<endl;
    }
     virtual ~Animal(){
        cout<<"~Animal"<<endl;
    }
    virtual void bark(){
        cout<<"bark"<<endl;
    }
};

class Dog : public Animal{
public:
    Dog(){
        cout<<"Dog"<<endl;
    }
    ~Dog(){
        cout<<"~Dog"<<endl;
    }
    void bark(){
        cout<<"wang"<<endl;
    }
};

int myAlloc(char*& p, int size){
    p = (char *)malloc(size);
    return p==NULL ? 1 : 0;
}

void test(){
    // Dog d;
    // Dog* d2 = new Dog();
    // cout<<"test"<<endl;
}


int main(){
    // Dog d;
    // Animal* a = &d;
    // a->bark();
    // // delete a;
    // test();
    // cout<<"ok"<<endl;
    char* p = NULL;
    if(myAlloc(p, 2)){
        return 1;
    }
    p = (char *)malloc(2);
    cout<<1<<endl;
    p[0] = 'x';
    p[1] = '\0';
    
    printf("%s\n",p);
    // delete p;
    return 0;
}