#include <iostream>
#include <cstring>
using namespace std;
#define size 10
class Person {

public:
    //string name; // object
    char* info; // pointer
public:
    Person() {
        //name = s;
        info = new char[size];
        std::cout << "constructor is invoked\n";
    }
    ~Person() {
        //std::cout << this->name;
        //~string(name);
        delete[] info;
        info = nullptr;
        std::cout << " destructor is invoked\n";
    }
    Person(const Person& other);

    Person& changeName1();
    Person& changeName2();
    Person changeName3();
};

Person& Person::changeName1() {
   std::cout << "call changeName1" << endl;
   
   std::cout << "ret changeName1" << endl;
   return *this;
}

Person& Person::changeName2() {
   cout << "call changeName2" << endl;
   Person p; // allocated on the stack
   // Person* p = new Person(); // allocated on the heap
   cout << "ret changeName2" << endl;
   return p;
}

Person Person::changeName3() {
    cout << "call changeName3" << endl;
    Person p;
    cout << "ret changeName3" << endl;
    return p;
}


Person::Person(const Person& other) {
    info = new char[size];
    strncpy(info, other.info, size);
}

int main() {
    std::cout << "In main:" <<endl;
    Person p1;
    std::cout << "origin : \n" << "info: " << & p1.info << endl;
    //the alias of p1
    Person& alias_p1 = p1.changeName1();
    std::cout << "alias : \n" << "info: " << &alias_p1.info << endl;
    std::cout << (&alias_p1 == &p1) << endl;

    cout << "----------------------" <<endl;

    Person p2;
    std::cout << "origin : \n" << "info: " << & p2.info << endl;
    //the alias of p2
    Person alias_p2 = p2.changeName2();
    // Person* alias_p2 = &(p2.changeName2());
    std::cout << "alias : \n" << "info: " << &alias_p2.info << endl;
    std::cout << (&alias_p2 == &p2) << endl;
    // delete alias_p2; // 释放通过 new 创建的对象内存

    cout << "--------------------------" << endl;

    Person p3;
    std::cout << "origin : \n" << "info: " << & p3.info << endl;
    //the alias of p3
    Person alias_p3 = p3.changeName3();
    std::cout << "alias : \n" << "info: " << &alias_p3.info << endl;
    std::cout << (&alias_p3 == &p3) << endl;

    return 0;
}
