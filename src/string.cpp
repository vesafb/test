#include "string.h"

class String {
  public:
    String();
    String(const char *v);
    ~String();
    String & operator=(const String &rhs);
  private:
    char * data;
};

String::String() {
  data = new char[1];
  data[0] = '\0';
}

String::String(const char *v) {
  if(v) {
    data = new char[strlen(v)+1];
    strcpy(data, v);
  } else {
    data = new char[1];
    data[0] = '\0';
  }
}

String & String::operator=(const String &rhs) {
  if(this==&rhs)
    return *this;
  delete [] data;
  data = new char[strlen(rhs.data) + 1];
  strcpy(data, rhs.data);
  return *this;
}

String::~String() {
  delete data;
}

int main() {
  String s1;
  String s2 = "hello";
  s1 = s2;
}
