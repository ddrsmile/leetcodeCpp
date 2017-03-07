#include <iostream>
#include <vector>
#include <string>
#include "sols.cpp"
#include "utils/InputHandler.cpp"
#include "utils/utils.h"

using namespace std;

int main(int argc, char* argv[]) {
    string path = GetFilePath(argc, argv);
    InputHandler ih(path);
    Solution sol = Solution();

    vector<vector<int>> inIntVector = ih.GetDataAsIntVector();
    for (int i = 0; i < inIntVector.size()/2; i++) {
        vector<int> nums = inIntVector[2*i];
        int target = inIntVector[2*i + 1][0];
        vector<int> res = sol.twoSum(nums, target);

        for (int j = 0; j < res.size(); j++) {
            cout << res[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
