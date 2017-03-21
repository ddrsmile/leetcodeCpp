#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <memory>
#include "IParser.cpp"

using namespace std;

template <class E>
class BaseParser: public IParser<E> {
    protected:
        string input_path_;
        vector<string> split(const string& str, char delim);
        vector<string> split(const string& str, const string& delim);
        string remove_space(const string& str);
        string find_and_replace(const string& str, const string& find, const string& replace);

        virtual E toValue(string& str) = 0; 
        vector<E> toList(string& str);
        vector<vector<E>> toLists(string& str);
};

template <class E>
vector<string> BaseParser<E>::split(const string& str, char delim) {
    stringstream ss(str);
    string token;
    vector<string> tokens;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

template <class E>
vector<string> BaseParser<E>::split(const string& str, const string& delim) {
    string::size_type pos = 0;
    string resource = str;
    string token;
    vector<string> tokens;
    while ((pos = resource.find(delim)) != string::npos) {
        token = resource.substr(0, pos);
        tokens.push_back(token);
        resource.erase(0, pos + delim.length());
    }
    tokens.push_back(resource);
    return tokens;
}

template <class E>
string BaseParser<E>::remove_space(const string& str) {
    string output = str;
    output.erase(remove_if(output.begin(),output.end(), [](char x){return isspace(x);}),output.end());
    return output;
}

template <class E>
string BaseParser<E>::find_and_replace(const string& str, const string& find, const string& replace) {
    string::size_type pos = 0;
    string output_str = str;
    while ((pos = output_str.find(find, pos) != string::npos)) {
        output_str.replace(pos, find.length(), replace);
        pos += replace.length();
    }
    return output_str;
}

template <class E>
vector<E> BaseParser<E>::toList(string& str) {
    vector<E> output;
    if (str[0] != '[' && str[str.size() - 1] != ']') {
        output.push_back(toValue(str));
    }

    str = str.substr(1, str.size() - 2);
    if (str.size() == 0) return output;
    str = this->remove_space(str);
    vector<string> input_contents = this->split(str, ',');
    for (vector<string>::iterator it = input_contents.begin(); it != input_contents.end(); it++) {
        output.push_back(this->toValue(*it));
    }
    return output;
}

template <class E>
vector<vector<E>> BaseParser<E>::toLists(string& str) {
    vector<vector<E>> output;
    if (str[0] != '[' && str[str.size() - 1] != ']') {
        output.push_back(this->toList(str));
    }

    str = str.substr(1, str.size() - 2);
    if (str.size() == 0) return output;
    str = this->remove_space(str);
    str = this->find_and_replace(str, "],[", "], [");
    vector<string> input_contents = this->split(str, ", ");
    for (vector<string>::iterator it = input_contents.begin(); it != input_contents.end(); it++) {
        output.push_back(this->toList(*it));
    }
    return output;
}