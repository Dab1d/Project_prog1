//
// Created by JBispo on 05/04/2025.
//

#ifndef PROJECT_BLANK_HPP
#define PROJECT_BLANK_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Blank : public Command {
        public:
            Blank(int w, int h, Color &fill);

            ~Blank();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int w;
            int h;
            Color fill;
        };
    }
}
#endif //PROJECT_BLANK_HPP
