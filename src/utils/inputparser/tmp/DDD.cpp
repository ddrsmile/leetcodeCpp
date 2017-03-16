#include <iostream>
#include <string>
#include "TTT.cpp"

using namespace std;

class DDD: public TTT<int> {
    public:
        virtual int get();
        DDD() {}
};

int DDD::get() {
    return 100;
}
