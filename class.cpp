#include<iostream>
using namespace std;

//Base Class
class Father{
    public:
        void FatherSay(){
            cout << "This is Father Saying" << endl;
        }

};

//Derive Class

class Child : public Father {
    public:
        void ChildSay(){
            cout << "This is Child Saying" << endl;
        }

};


int main () {
    Father father;
    Child child;
    cout << "Father Class Say" << endl;
    father.FatherSay();
    cout << "Child Class Say" << endl;
    child.ChildSay();
    cout << "Child inherits from Father Say" << endl;
    child.FatherSay();
    return 0;
    
}