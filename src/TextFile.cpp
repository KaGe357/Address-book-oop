#include "TextFile.h"
//#include <stdlib.h>


string TextFile::getFilename()
{
    return FILE_NAME;
}
bool TextFile::isFileEmpty(ifstream& file) const
{
    return file.peek() == ifstream::traits_type::eof();
}

bool TextFile::isFileEmpty(ofstream& file) const
{

    string filePath = FILE_NAME;
    ifstream tempFile(filePath);
    return tempFile.peek() == ifstream::traits_type::eof();
}
