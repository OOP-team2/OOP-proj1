#ifndef OOP_PROJ1_FILEMANAGER_H
#define OOP_PROJ1_FILEMANAGER_H

#include "Parser.h"
#include "string"
#include "vector"
#include "iostream"
#include "fstream"

// Abstract Class for file managers
class FileManager {
private:
    // string variable for txt file name
    std::string file_name;
public:
    // a virtual fucntion to be overrided to load txt file database
    virtual std::vector<std::vector< std::string> > loadDB() = 0;

};

// Class for managing txt file saves Recipe Data to read and write
class FileManagerForRecipes : public FileManager{
    private:
        // string variable for txt file name
        std::string file_name;
    
    public:
        // default constructor
        FileManagerForRecipes();
        // constructor for new txt file
        FileManagerForRecipes(std::string new_file_name);
        // function to load txt and returns vectorized string values
        virtual std::vector<std::vector< std::string> > loadDB();
        // function to write txt with vectorized string values
        void writeRecipeDB(std::vector<std::vector<std::string>> data);
};

// Class for managing txt file save Plan Data to read and write
class FileManagerForPlans : public FileManager {
private:
    // string variable for txt file name
    std::string file_name;
public:
    // default constructor
    FileManagerForPlans();
    // constructor for new txt file
    FileManagerForPlans(std::string file_name);
    // function to load txt and returns vectorized string values
    virtual std::vector<std::vector< std::string> > loadDB();
    // function to write txt with vectorized string values
    void writePlans(std::vector<std::string> plandata);
};


#endif