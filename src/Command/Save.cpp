//
// Created by JBispo on 05/04/2025.
//
#include "Command/Save.hpp"
#include "PNG.hpp"
#include "Utils.h"
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

namespace prog {

    namespace command {

        Save::Save(std::string filename) : Command("Save"), filename(filename) {

        }

        Save::~Save() {}

        Image *Save::apply(Image *img) {

            // Ensure folder exists before writing file
            fs::path filepath(filename);
            mkdir(filepath.parent_path().string());

            saveToPNG(filename, img);

            return img;
        }

        std::string Save::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename;
            return ss.str();
        }
    }
}