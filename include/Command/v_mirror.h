//
// Created by Eduardo on 15/05/2025.
//

#ifndef VMIRROR_H
#define VMIRROR_H
#include "Image.hpp"
#include "Command.hpp"

namespace prog {
    namespace command {
        class v_mirror : public Command {
          public:
            v_mirror();

            ~v_mirror();

            Image* apply(Image* base_img) override;
        };
    }
}
#endif //V_MIRROR_H
