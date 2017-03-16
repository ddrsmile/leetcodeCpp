#include <iostream>
#include <memory>
#include "AAA.cpp"

class BBB: public AAA {
    public:
        virtual void push();
        void push_back();
        void push_front();
        BBB() {}
    protected:
        void push_kk();
};

void BBB::push() {
    std::cout << "push from BBB" << std::endl;
}

void BBB::push_back() {
    std::cout << "push back from BBB"<< std::endl;
}
void BBB::push_kk() {
    std::cout << "push front from BBB protected"<< std::endl;
}
void BBB::push_front() {
    push_kk();
}
