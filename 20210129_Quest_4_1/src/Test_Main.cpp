// Student ID: 20382528
// Quest: Krazy the Koala

#include "Tree.h"

#include <iostream> // cout
#include <vector> // vector

using namespace std;

int main()
{
    Tree tree;
    cout << tree << endl;

    vector<string> names = { "AABA", "ABAB", "ABBA", "BABA", "COBO", "COCO",
        "CODO", "COFO", "COGO", "COHO", "COJO", "COKO", "DIBI", "DIDI", "DIFI",
        "DIGI", "DIHI", "DIJI", "DIKI", "DILI" };
    tree.make_special_config_1(names);
    cout << tree << flush;

    return 0;
}

/* Output
# Tree rooted at ROOT
# The following lines are of the form:
#   node: child1 child2...
ROOT :
# End of Tree

# Tree rooted at ROOT
# The following lines are of the form:
#   node: child1 child2...
ROOT :
# Next sib of ROOT
AABA : COBO COCO
# Child of AABA
COBO : DIBI
# Child of COBO
DIBI :
# Next sib of COBO
COCO : DIDI
# Child of COCO
DIDI :
# Next sib of AABA
ABAB : CODO COFO
# Child of ABAB
CODO : DIFI
# Child of CODO
DIFI :
# Next sib of CODO
COFO : DIGI
# Child of COFO
DIGI :
# Next sib of ABAB
ABBA : COGO COHO
# Child of ABBA
COGO : DIHI
# Child of COGO
DIHI :
# Next sib of COGO
COHO : DIJI
# Child of COHO
DIJI :
# Next sib of ABBA
BABA : COJO COKO
# Child of BABA
COJO : DIKI
# Child of COJO
DIKI :
# Next sib of COJO
COKO : DILI
# Child of COKO
DILI :
# End of Tree

*/
