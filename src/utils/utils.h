#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#ifndef UTLIS_H
#define UTILS_H

// parse commandline input
string GetFilePath(int argc, char* argv[]) {
    string path;
    if (argc == 2) {
        path = argv[1];
    } else {
        path = "";
    }
    return path;
}

#endif

