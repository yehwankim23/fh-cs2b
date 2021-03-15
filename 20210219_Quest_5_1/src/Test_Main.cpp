// Student ID: 20382528
// Quest: The Complex Kiwi

#include "Complex.h"

#include <iostream> // cout

using namespace std;

int main()
{
    Complex complex1(3, 14), complex2(15, 92);
    cout << complex1 << endl;
    cout << complex2 << endl;

    cout << complex1 + complex2 << endl;
    cout << complex1 - complex2 << endl;
    cout << complex1 * complex2 << endl;
    cout << complex1 / complex2 << endl;

    cout << (complex1 == complex2) << endl;
    cout << (complex1 < complex2) << endl;

    return 0;
}

/* Output
(3,14)
(15,92)
(18,106)
(-12,-78)
(-1243,486)
(0.15341236046,-0.0075958107953)
0
1

*/
