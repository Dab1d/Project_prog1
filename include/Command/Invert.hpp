//
// Created by 2006d on 12/05/2025.
//

#ifndef INVERT_H
#define INVERT_H

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class invert : public Command {
        public:
            invert();

            ~invert();

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}


#endif //INVERT_H
