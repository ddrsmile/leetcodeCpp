#include <iostream>
#include <string>
#include "BBB.cpp"

using namespace std;

class CCC: public BBB {
    public:
        void take();
        void take_back();
        void show(const string& str);
        CCC() {}
};
void CCC::take() {
    std::cout << "take from CCC" << std::endl;
}
void CCC::take_back() {
    BBB::push_kk();
}
void CCC::show(const string& str) {
    string kk = str;
    std::cout << str[0] << endl;
    std::cout << str[str.size() - 1] << endl;
    std::cout << kk << endl;
}
