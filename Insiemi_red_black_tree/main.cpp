#include "SetGenerator.h"

int main()
{
    SetGenerator setGenerator{"input1_1_0.txt"};

    vector<NumSet> sets = setGenerator.generate_sets();

    for(auto set:sets)
    {
        set.inorder();
        cout << endl;
    }
    return 0;
}