//feito tiago 15/5
#ifndef SCALEUP_COMMAND_HEADER
#define SCALEUP_COMMAND_HEADER

#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class scaleup : public Command {
        public:
            scaleup(int factorX, int factorY);
            Image* apply(Image* src) override;
            std::string toString() const override;
        private:
            int scalex, scaley;
        };
    }
}
#endif