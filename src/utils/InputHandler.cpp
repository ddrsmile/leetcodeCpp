#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class InputHandler {
    private:
        string inputPath;

        // helper methods
        vector<string> split(const string& str, char delim);

        // Integer containers
        vector<int> inInt;
        vector<vector<int>> inIntVector;
        vector<vector<vector<int>>> inIntVectors;
        

        int getInt(string str);
        vector<int> getIntVector(string str);

    public:
        // constructor
        InputHandler(string inputPath);

        // methods
        vector<vector<int>> getDataAsIntVector();
};

vector<string> InputHandler::split(const string& str, char delim) {
    stringstream ss(str);
    string token;
    vector<string> tokens;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

InputHandler::InputHandler(string inputPath) {
    this->inputPath = inputPath;
}

int InputHandler::getInt(string str) {
    return stoi(str);
}

vector<int> InputHandler::getIntVector(string str) {
    if (str[0] != '[' && str[str.size() - 1] != ']') {
        vector<int> tmp = {stoi(str)};
        return tmp;
    }
    str = str.substr(1, str.size() - 2);
    if (str.size() == 0) return vector<int>();
    str.erase(remove(str.begin(),str.end(),' '),str.end());
    vector<string> ints = this->split(str, ',');
    vector<int> out(ints.size());
    for (int i = 0; i < ints.size(); i++) {
        out[i] = stoi(ints[i]);
    }
    return out;
}

vector<vector<int>> InputHandler::getDataAsIntVector() {
    if (this->inputPath.size() == 0) {
        return this->inIntVector;
    }
    string str;
    ifstream ins(this->inputPath);
    while (getline(ins, str)) {
        this->inIntVector.push_back(this->getIntVector(str));
    }
    return this->inIntVector;
}