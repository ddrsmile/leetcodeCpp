#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class InputHandler {
    private:
        string input_path_;

        // helper methods
        vector<string> split(const string& str, char delim);
        vector<string> split(const string& str, const string& delim);
        string find_and_replace(const string& str, const string& find, const string& replace);

        // integer methods
        vector<int> get_int_vector(string str);
        vector<vector<int>> get_int_vectors(string str);

    public:
        // constructor
        InputHandler(string inputPath);

        // public methods
        vector<int> GetDataAsInt();
        vector<vector<int>> GetDataAsIntVector();
        vector<vector<vector<int>>> GetDataAsIntVectors();
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

vector<string> InputHandler::split(const string& str, const string& delim) {
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

string InputHandler::find_and_replace(const string& str, const string& find, const string& replace) {
    string::size_type pos = 0;
    string output_str = str;
    while ((pos = output_str.find(find, pos) != string::npos)) {
        output_str.replace(pos, find.length(), replace);
        pos += replace.length();
    }
    return output_str;
}

InputHandler::InputHandler(string input_path) {
    this->input_path_ = input_path;
}

vector<int> InputHandler::get_int_vector(string str) {
    if (str[0] != '[' && str[str.size() - 1] != ']') {
        return {stoi(str)};
    }
    vector<int> output_vector;
    str = str.substr(1, str.size() - 2);
    if (str.size() == 0) return output_vector;
    str.erase(remove_if(str.begin(),str.end(), (int(*)(int))isspace),str.end());
    vector<string> int_vector = this->split(str, ',');
    for (vector<string>::iterator it = int_vector.begin(); it != int_vector.end(); it++) {
        output_vector.push_back(stoi(*it));
    }
    return output_vector;
}

vector<vector<int>> InputHandler::get_int_vectors(string str) {
    vector<vector<int>> output_vector;
    if (str[0] != '[' && str[str.size() - 1] != ']') {
        output_vector.push_back({stoi(str)});
    }
    str = str.substr(1, str.size() - 2);
    if (str.size() == 0) return output_vector;
    str = this->find_and_replace(str, "],[", "], [");
    vector<string> int_vectors = this->split(str, ", ");
    for (vector<string>::iterator it = int_vectors.begin(); it != int_vectors.end(); it++) {
        output_vector.push_back(this->get_int_vector(*it));
    }
    return output_vector;
}

vector<int> InputHandler::GetDataAsInt() {
    vector<int> output_vector;
    if (this->input_path_.size() == 0) {
        return output_vector;
    }
    string str;
    ifstream input_contents(this->input_path_);
    while (getline(input_contents, str)) {
        output_vector.push_back(stoi(str));
    }
    return output_vector;
}

vector<vector<int>> InputHandler::GetDataAsIntVector() {
    vector<vector<int>> output_vector;
    if (this->input_path_.size() == 0) {
        return output_vector;
    }
    string str;
    ifstream input_contents(this->input_path_);
    while (getline(input_contents, str)) {
        output_vector.push_back(this->get_int_vector(str));
    }
    return output_vector;
}

vector<vector<vector<int>>> InputHandler::GetDataAsIntVectors() {
    vector<vector<vector<int>>> output_vector;
    if (this->input_path_.size() == 0) {
        return output_vector;
    }
    string str;
    ifstream input_contents(this->input_path_);
    while (getline(input_contents, str)) {
        output_vector.push_back(this->get_int_vectors(str));
    }
    return output_vector;
}