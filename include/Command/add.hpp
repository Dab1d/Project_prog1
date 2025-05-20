// done by tiago

#ifndef ADD_COMMAND_HEADER
#define ADD_COMMAND_HEADER

#include "Command.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {
        class add : public Command {
        public:
            add(const std::string& file_path, const Color& ignore_color, int posx, int posy);
            Image* apply(Image* base_img) override;
            std::string toString() const override;

        private:
            std::string file_path;
            Color ignore_color;
            int posx, posy;
        };
    }
}
#endif