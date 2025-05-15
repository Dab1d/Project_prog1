//
// Created by Eduardo on 15/05/2025.
//

#ifndef VMIRROR_H
#define VMIRROR_H
#include "Image.hpp"
#include "Command.hpp"

namespace prog {
    namespace command {
        class Vmirror : public Command {
          public:
            Vmirror();

            ~Vmirror();

            Image* apply(Image* base_img) override;
        };
    }
}
#endif //VMIRROR_H
