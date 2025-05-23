#ifndef VMIRROR_HPP
#define VMIRROR_HPP
#include "Image.hpp"
#include "Command.hpp"

namespace prog {
    namespace command {
        class v_mirror : public Command {
          public:
            v_mirror();

            ~v_mirror();

            Image* apply(Image* base_img) override;

            std::string toString() const override;
        };
    }
}
#endif //V_MIRROR_H
