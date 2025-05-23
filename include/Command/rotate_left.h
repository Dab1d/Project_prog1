#ifndef ROTATE_LEFT_H
#define ROTATE_LEFT_H
#include "Image.hpp"
#include "Command.hpp"
#include <string>
namespace prog {
    namespace command {

        class rotate_left : public Command {
        public:
            rotate_left(); // constructor

            ~rotate_left(); // destructor

            Image* apply(Image* base_img) override;

            std::string toString() const override;
        };
    }
}
#endif
