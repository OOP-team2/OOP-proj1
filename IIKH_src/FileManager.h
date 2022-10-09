#ifndef OOP_PROJ1_FILEMANAGER_H
#define OOP_PROJ1_FILEMANAGER_H

#include "string"
#include "vector"

// Class for managing txt file saves Recipe Data to read and write
class FileManager{
    private:
        // string variable for txt file name
        std::string file_name;
    
    public:
        // default constructor
        FileManager();
        // constructor for new txt file
        FileManager(std::string new_file_name);
        // function to load txt and returns vectorized string values
        std::vector<std::vector< std::string> > loadRecipeDB();
        // function to write txt with vectorized string values
        void writeRecipeDB(std::vector<std::vector<std::string>> data);
};

// Class for managing txt file save Plan Data to read and write
class FileManagerForPlans {
private:
    // string variable for txt file name
    std::string file_name;
public:
    // default constructor
    FileManagerForPlans();
    // constructor for new txt file
    FileManagerForPlans(std::string file_name);
    // function to load txt and returns vectorized string values
    std::vector<std::vector< std::string> > loadPlans();
    // function to write txt with vectorized string values
    void writePlans(std::vector<std::string> plandata);
};


#endif