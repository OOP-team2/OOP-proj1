#ifndef OOP_PROJ1_FILEMANAGER_H
#define OOP_PROJ1_FILEMANAGER_H

#include <string>
#include "vector"

class FileManager{
    private:
        string file_name;
    
    public:
        FileManager(string file_name);
        load(string recipes);
        write(string recipes);
}

#endif