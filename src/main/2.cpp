#include <iostream>
#include <vector>
#include <string>
#include "sols.cpp"
#include "objs/listnode.h"
#include "utils/InputHandler.cpp"
#include "utils/ListNodes.cpp"
#include "utils/utils.h"

using namespace std;

int main(int argc, char* argv[]) {
    string path = argsparse(argc, argv);
    InputHandler ih(path);
    ListNodes listnodes = ListNodes();
    Solution sol = Solution();

    vector<vector<int>> inIntVector = ih.getDataAsIntVector();
    for (int i = 0; i < inIntVector.size()/2; i++) {
        ListNode* l1 = listnodes.getList(inIntVector[2*i]);
        ListNode* l2 = listnodes.getList(inIntVector[2*i + 1]);
        
        ListNode* res = sol.addTwoNumbers(l1, l2);
        if (res) {
            while (res->next) {
                cout << res->val << ", ";
                res = res->next;
            }
            cout << res->val << endl;
        } else {
            cout << "no output!!" << endl;
        }
    }

    return 0;
}
