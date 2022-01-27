#include <iostream>
using namespace std;
int main()
{
    cout << "Hello, world!" << endl;
    int a = 1;
    a <<=10;
    cout << a << endl;


    int x = 4407873;

    cout << (char * ) &x <<endl;


    int y = 0x434241;

    cout << (char *) &y <<endl;
    return 0;
}
