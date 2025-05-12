//
// Created by 2006d on 12/05/2025.
//

#ifndef INVERT_H
#define INVERT_H

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            Invert();

            ~Invert();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}


#endif //INVERT_H
