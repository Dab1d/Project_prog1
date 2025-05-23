#ifndef INVERT_H
#define INVERT_H

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            Invert(); // constructor

            ~Invert(); // destructor

            Image *apply(Image *img) override;

            std::string toString() const override;
        };
    }
}


#endif
