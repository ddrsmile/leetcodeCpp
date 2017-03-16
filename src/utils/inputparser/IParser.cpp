#include <vector>
#include <memory>
using namespace std;

template <class E>
class IParser {
    public:
        virtual vector<E> parseDataAsSingleValue() = 0; 
        virtual vector<vector<E>> parseDataAsList() = 0;
        virtual vector<vector<vector<E>>> parseDataAsLists() = 0;
};