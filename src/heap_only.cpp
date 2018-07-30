#include <stdlib.h>
using namespace std;
class StackOnly {
  public:
    StackOnly() {};
    ~StackOnly() {};
  private:
    void *operator new(size_t) {};
};

class HeapOnly {
   public:
     HeapOnly() {};
     void destroy() {};
   private:
     ~HeapOnly() {};
};

int main() {
  //StackOnly *s1 = new StackOnly();
  StackOnly s2;
  HeapOnly *h1 = new HeapOnly();
  //HeapOnly h2;
}
