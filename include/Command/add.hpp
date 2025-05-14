// fieto por megaman no dia 14del5

#ifndef ADD_COMMAND_HEADER
#define ADD_COMMAND_HEADER

#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        class add : public Command {
        public:
            add(const std::string& file_path, const Color& ignore_color, int pos_x, int pos_y);
            Image* apply(Image* base_img) override;
            std::string toString() const override;

        private:
            std::string file_path;
            Color ignore_color;
            int pos_x, pos_y;
        };
    }
}

#endif