#ifndef OOP_PROJ1_FILEMANAGER_H
#define OOP_PROJ1_FILEMANAGER_H

#include "string"
#include "vector"

class FileManager{
    private:
        std::string file_name;
        vector<string> split(string str, char Delimiter);
    
    public:
        FileManager();
        std::vector<std::vector< std::string> > load();
        void write(std::string recipes);
};

#endif