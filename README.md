BigInt
==============
BigInt Class

Example
-----------
``` cpp
#include <iostream>
#include "BigInt.hpp"
#include <string>
using namespace std;

int main()
{
    string zresult="";
    for(int i=1;i<=2015;i++)
        zresult+=to_string(i);
    BigInt bi(zresult);
    cout<<bi%9;
}
```
