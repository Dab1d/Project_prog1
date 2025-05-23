#ifndef SCALEUP_COMMAND_HEADER
#define SCALEUP_COMMAND_HEADER

#include "Command.hpp"
#include "Color.hpp"
#include <string>

using namespace std;

namespace prog {
    namespace command {
        class scaleup : public Command {
        public:
            scaleup(int factorx, int factory); // construtor
            Image* apply(Image* src) override;
            string toString() const override;

        private:
            int scalex, scaley;
        };
    }
}
#endif