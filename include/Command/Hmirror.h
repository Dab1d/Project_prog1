//
// Created by Eduardo on 15/05/2025.
//

#ifndef HMIRROR_H
#define HMIRROR_H
#include "Image.hpp"
#include "Command.hpp"

namespace prog {
    namespace command {
        class Hmirror : public Command {
        public:
            Hmirror();

            ~Hmirror();

            Image* apply(Image* base_img) override;
        };
    }
}
#endif //HMIRROR_H
