//
// Created by JBispo on 05/04/2025.
//

#ifndef PROJECT_SAVE_HPP
#define PROJECT_SAVE_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Save : public Command {
        public:
            Save(std::string filename);

            ~Save();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            std::string filename;
        };
    }
}


#endif //PROJECT_SAVE_HPP
