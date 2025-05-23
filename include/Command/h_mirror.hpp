#ifndef H_MIRROR_HPP
#define H_MIRROR_HPP
#include "Image.hpp"
#include "Command.hpp"

namespace prog {
    namespace command {
        class h_mirror : public Command {
        public:
            h_mirror(); //constructor

            ~h_mirror(); //destructor

            Image* apply(Image* base_img) override;

            std::string toString() const override;
        };
    }
}
#endif
