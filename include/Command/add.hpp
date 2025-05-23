#ifndef ADD_COMMAND_HEADER
#define ADD_COMMAND_HEADER

#include "Command.hpp"
#include "Color.hpp"
#include <string>

using namespace std;

namespace prog {
    namespace command {
        class add : public Command {
        public:
            add(const string& file_path, const Color& ignore_color, int posx, int posy); // constructor
            Image* apply(Image* base_img) override;
            string toString() const override;

        private:
            string file_path;
            Color ignore_color;
            int posx, posy;
        };
    }
}
#endif