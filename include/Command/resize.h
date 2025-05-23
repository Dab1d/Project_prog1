#ifndef RESIZE_H
#define RESIZE_H
#include <string>
#include "Command.hpp"

namespace prog {
    namespace command {
        class resize: public Command {

        public:
            resize(int x,int y, int w, int h); // constructor

            ~resize(); //destructor

            Image *apply(Image *img) override;

            std::string toString() const override;
        private:
            int x_, y_, w_ ,h_;
        };
    }
}
#endif
