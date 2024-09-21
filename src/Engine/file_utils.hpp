#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class file_utils {
    
public:
    static std::string read_file(const char* path) {

        std::ifstream file;
        std::string result;

        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try {
            file.open(path);
            std::stringstream result_stream;

            result_stream << file.rdbuf();
            file.close();
            result = result_stream.str();
        }
        catch (std::ifstream::failure e) {
            std::cout << "ERROR: Failed to read file: " << path << std::endl;
        }

        return result.c_str();

    }
};