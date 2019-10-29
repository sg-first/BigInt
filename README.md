BigInt
==============
Big Number computer Class

BigInt Example
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

Fraction Example
--------------
``` cpp
#include <iostream>
#include <string>
#include "Fraction.hpp"
using namespace std;

int main()
{
    //原测试
    Fraction rat0;
    cout << rat0 << endl;
    Fraction rat1 = -rat0;
    cout << rat1 << endl;
    Fraction rat2 = rat1 + 34;
    cout << rat2 << endl;
    Fraction rat3;
    rat3 = 12 + rat2;
    rat3++;
    cout << rat3 << endl;
    cout << (string)rat3 << endl;
    //新测试
    cout<<"newTest:"<<endl;
    rat0=Fraction(2,3);
    rat1=Fraction(3,5);
    cout<<rat0+rat1<<endl;
    cout<<rat0-rat1<<endl;
    cout<<rat0/rat1<<endl;
    cout<<rat0*rat1<<endl;
    //求和
    cout<<"sum:"<<endl;
    Fraction result(1,2);
    for(unsigned int i=2;i<=49;i++)
        result=result+Fraction(i,i+1);
    cout<<result<<endl;
    cout<<(string)result<<endl;
}
```