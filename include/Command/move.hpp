#ifndef MOVE_COMMAND_HEADER
#define MOVE_COMMAND_HEADER

#include "Command.hpp"
#include "Color.hpp"
#include <string>

using namespace std;

namespace prog {
    namespace command {
        class move : public Command {
            public:
                move(int offsetx, int offsety); // constructor
                Image* apply(Image* img) override;
                string toString() const override;

            private:
                int offsetx, offsety;
        };
    }
}
#endif