#ifndef OOP_PROJ1_FILEMANAGER_H
#define OOP_PROJ1_FILEMANAGER_H

#include "string"
#include "vector"

class FileManager{
    private:
        std::string file_name;
    
    public:
        FileManager();
        FileManager(std::string new_file_name);
        std::vector<std::vector< std::string> > loadRecipeDB();
        void writeRecipeDB(std::vector<std::string> data);
};

class FileManagerForPlans {
private:
    std::string file_name;
public:
    FileManagerForPlans();
    FileManagerForPlans(std::string file_name);
    std::vector<std::vector< std::string> > loadPlans();
    void writePlans(std::vector<std::vector<std::string>> plandata);
};


#endif