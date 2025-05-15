// feito pelo MegaMan dia 12 de maio

#ifndef PROJECT_COMMAND_SLIDE_HPP
#define PROJECT_COMMAND_SLIDE_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        class Slide : public Command {
            public:

                Slide(int offset_x, int offset_y);

                Image* apply(Image* img) override;

                std::string toString() const override;

            private:
                int x_offset;
                int y_offset;
        };
    }
}

#endif
