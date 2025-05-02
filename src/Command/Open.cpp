//
// Created by JBispo on 05/04/2025.
//
#include "Command/Open.hpp"
#include "PNG.hpp"
#include "Logger.hpp"
#include <cstdlib>
#include <sstream>

namespace prog {

    namespace command {
        Open::Open(std::string filename) : Command("Open"), filename(filename) {}

        Open::~Open() {};

        Image *Open::apply(Image *img) {
            // Dispose of previous image
            delete img;

            // TODO:  fix rootpath
            // img = loadFromPNG("../"+filename);
            img = loadFromPNG(filename);

            if (!img) {
                *Logger::err() << "Could not open file " << filename << "\n";
                std::exit(1);
            }

            return img;
        }

        std::string Open::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename;
            return ss.str();
        }
    }
}