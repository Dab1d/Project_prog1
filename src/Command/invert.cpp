#include "Command/Invert.h"
namespace prog {

    namespace command {

        Invert::Invert() : Command("Invert"){}

        Invert::~Invert() {};

        Image *Invert::apply(Image *img) {


            delete img;
            return new Image(w,h,(255-r,255-g,255-b));
        }


        std::string Invert::toString() const {
            std::ostringstream ss;
            ss << name() << " w:" << w << " h:" << h << " fill:" << fill;
            return ss.str();
        }

    }
}