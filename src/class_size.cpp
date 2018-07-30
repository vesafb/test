#include <iostream>
using namespace std;
class Parent {
  public:
    Parent() {};
    virtual ~Parent() {};
  private:
    int a;
    char c;
    char *p;
};

class Child: public Parent {
  public:
    Child() {};
    ~Child() {};
  private:
    int a;
};

int main() {
  cout << sizeof(Parent) << endl;
  cout << sizeof(Child) << endl;
}

