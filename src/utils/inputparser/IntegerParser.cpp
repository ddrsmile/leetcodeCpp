#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include "BaseParser.cpp"

using namespace std;

class IntegerParser: public BaseParser<int> {
    public:
        virtual vector<int> parseDataAsSingleValue(); 
        virtual vector<vector<int>> parseDataAsList();
        virtual vector<vector<vector<int>>> parseDataAsLists();
        IntegerParser(const string& input_path);

    protected:
        vector<string> split(const string& str, char delim);
        vector<string> split(const string& str, const string& delim);
        string remove_space(const string& str);
        string find_and_replace(const string& str, const string& find, const string& replace);

        virtual int toValue(string& str);
};

IntegerParser::IntegerParser(const string& input_path) {
    this->input_path_ = input_path;
}

int IntegerParser::toValue(string& str) {
    return stoi(str);
}

vector<int> IntegerParser::parseDataAsSingleValue() {
    vector<int> output;
    if (this->input_path_.size() == 0) {
        return output;
    }
    string str;
    ifstream input_contents(this->input_path_);
    while (getline(input_contents, str)) {
        output.push_back(this->toValue(str));
    }
    return output;
}
vector<vector<int>> IntegerParser::parseDataAsList() {
    vector<vector<int>> output;
    if (this->input_path_.size() == 0) {
        return output;
    }
    string str;
    ifstream input_contents(this->input_path_);
    while (getline(input_contents, str)) {
        output.push_back(this->toList(str));
    }
    return output;
}
vector<vector<vector<int>>> IntegerParser::parseDataAsLists() {
    vector<vector<vector<int>>> output;
    if (this->input_path_.size() == 0) {
        return output;
    }
    string str;
    ifstream input_contents(this->input_path_);
    while (getline(input_contents, str)) {
        output.push_back(this->toLists(str));
    }
    return output;
}