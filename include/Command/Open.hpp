//
// Created by JBispo on 05/04/2025.
//

#ifndef PROJECT_OPEN_HPP
#define PROJECT_OPEN_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Open : public Command {
        public:
            Open(std::string filename);

            ~Open();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            std::string filename;
        };
    }
}


#endif //PROJECT_OPEN_HPP
