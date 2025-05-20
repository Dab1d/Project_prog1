// done by tiago

#ifndef PROJECT_COMMAND_SLIDE_HPP
#define PROJECT_COMMAND_SLIDE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        class Slide : public Command {
            public:
                Slide(int offsetx, int offsety);
                Image* apply(Image* img) override;
                std::string toString() const override;

            private:
                int offsetx, offsety;
        };
    }
}
#endif