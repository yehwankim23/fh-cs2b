// Student ID: 20382528
// Quest: Hare Today Hanoi Tomorrow

#include "Hanoi.h"

#include <iostream> // cout

using namespace std;

int main()
{
    Hanoi hanoi;

    cout << hanoi.solve(4, 3, 2, 1) << flush;
    return 0;
}

/* Output
# Below, 'A->B' means 'move the top disc on pole A to pole B'
3->1
3->2
1->2
3->1
2->3
2->1
3->1
3->2
1->2
1->3
2->3
1->2
3->1
3->2
1->2

*/
