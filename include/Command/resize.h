//
// Created by 2006d on 18/05/2025.
//

#ifndef RESIZE_H
#define RESIZE_H
#include <string>
#include "Command.hpp"

namespace prog {
    namespace command {
        class resize: public Command {

        public:
            resize(int x,int y, int w, int h);

            ~resize();

            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            int x_, y_, w_ ,h_;
        };
    }
}
#endif //RESIZE_H
