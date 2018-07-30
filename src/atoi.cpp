#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <exception>
using namespace std;
                                                                                
const unsigned int SIGN_BIT = 0x1 << 31;
 
int atoi_i(const char *str)
{
    assert(str != NULL);

    while (' ' == *str){ str++; }

    int result = 0;
    bool signFlag = false;
    if ('+' == *str)
    {
         ++str;
    }
    else if ('-' == *str)
    {
         signFlag = true;
         ++str;
    }
    else if (*str > '9' || *str < '0')
    {
         throw "input format error!";
    }

    do
    {
        if (*str > '9' || *str < '0')
        {
             throw "input format error!";
        }
        result = result * 10 + *str++ - '0';
        if (result < 0)
        {
            throw "overflow error!";
        }
    } while (*str != '\0');

    if (signFlag)
    {
        result = -result;
    }

    return result;
}
 
int main(int argc, char *argv[])
{
    char input[1024];
    while (1)
    {
        try
        {
            cout << "Input Array:";
            cin >> input;
            printf("exchange:%d/n", atoi_i(input));
        }
        catch (const char *p)
        {
            cout <<"Error Info:" << p << endl;
        }
        catch ( ... )
        {
            cout << "test" << endl;
        }
    }
    return 0;
}
