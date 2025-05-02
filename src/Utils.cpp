//
// Created by joaob on 15/04/2025.
//
#include "Utils.h"
#include <filesystem>
#include <iostream>

using std::string;

namespace fs = std::filesystem;

namespace prog {

    bool mkdir(const std::string & foldername) {

        if (!foldername.empty() && !fs::exists(foldername)) {
            std::error_code ec;
            if (fs::create_directories(foldername, ec)) {
                return true;
            }

            if (ec) {
                std::cerr << "Failed to create directory: " << ec.message() << "\n";
                return false;
            }

            std::cerr << "Failed to create directory\n";
            return false;
        }

        return true;
     }

     bool delete_files(std::string const & foldername) {

        if (!fs::exists(foldername) || !fs::is_directory(foldername)) {
            std::cerr << "Invalid folder name for deletion: '" << foldername << "'\n";
            return false;
        }

        for (const auto& entry : fs::directory_iterator(foldername)) {
            if (fs::is_regular_file(entry)) {
                fs::remove(entry.path());
            }
        }

        return true;
     }

}
