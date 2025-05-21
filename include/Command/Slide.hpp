// done by tiago

#ifndef PROJECT_COMMAND_SLIDE_HPP
#define PROJECT_COMMAND_SLIDE_HPP

#include "Command.hpp"
#include "Image.hpp"

using namespace std;

namespace prog {
    namespace command {
        class Slide : public Command {
            public:
                Slide(int offsetx, int offsety);
                Image* apply(Image* img) override;
                string toString() const override;

            private:
                int offsetx, offsety;
        };
    }
}
#endif