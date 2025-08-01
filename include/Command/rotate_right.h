#ifndef ROTATE_RIGHT_H
#define ROTATE_RIGHT_H
#include "Image.hpp"
#include "Command.hpp"
#include <string>
namespace prog {
    namespace command {

        class rotate_right : public Command {
        public:
            rotate_right(); // constructor

            ~rotate_right(); // destructor

            Image* apply(Image* base_img) override;

            std::string toString() const override;
        };
    }
}
#endif
