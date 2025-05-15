// feito megaman 15/5

#ifndef MOVE_COMMAND_HEADER
#define MOVE_COMMAND_HEADER

#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class move : public Command {
            public:
                move(int offsetx, int offsety);
                Image* apply(Image* img) override;
                std::string toString() const override;

            private:
                int offsetx;
                int offsety;
        };
    }
}
#endif