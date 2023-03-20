#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(){}
	Person(const Person& p)
	{
		cout << "Copy Constructor" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Assign" << endl;
		return *this;
	}
    // Person(const Person&& p)
	// {
	// 	cout << "move Constructor" << endl;
	// }
    // Person& operator=(const Person&& p)
	// {
	// 	cout << "move" << endl;
	// 	return *this;
	// }
    int get_age(){
        return age;
    }
private:
	int age;
	string name;
};

void f(Person p)
{
	return;
}

Person f1()
{
	Person p;
	return p;
}

int main()
{
	Person p;
	Person p1 = p;    // 1
	Person p2;
	p2 = p;           // 2
	f(p2);            // 3

	p2 = f1();        // 4
    cout<<5<<endl;
	Person p3 = f1(); // 5
    cout<<p3.get_age();
    cout<<5<<endl;
	// getchar();
	return 0;
}