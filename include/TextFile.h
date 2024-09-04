#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile {

protected:
    const string FILE_NAME;
    bool isFileEmpty(ifstream& file) const;
    bool isFileEmpty(ofstream& file) const;
public:
    TextFile(string filename) : FILE_NAME(filename){}
    fstream textFile;
    string getFilename();

};

#endif
