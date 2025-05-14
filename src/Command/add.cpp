// feito por megaman dia 14 do 5

#include "Command/add.hpp"
#include "PNG.hpp"

namespace prog {
    namespace command {

        add::add(const std::string& filename, const Color& neutral, int x_offset, int y_offset)
            : Command("add"), filename(filename), neutral_color(neutral),
              x_offset(x_offset), y_offset(y_offset) {}

        Image* add::apply(Image* img) {
            Image* overlay_img = loadFromPNG(filename);

            int dest_w = img->width();
            int dest_h = img->height();
            int src_w = overlay_img->width();
            int src_h = overlay_img->height();

            for (int sy = 0; sy < src_h; ++sy) {
                for (int sx = 0; sx < src_w; ++sx) {
                    const Color& current = overlay_img->at(sx, sy);

                    // ve se o pixel tem cor neutra
                    if (current.red() == neutral_color.red() &&
                        current.green() == neutral_color.green() &&
                        current.blue() == neutral_color.blue()) {
                        continue;
                        }

                    int tx = x_offset + sx;
                    int ty = y_offset + sy;

                    // so copia se tiver nos limites
                    if (tx >= 0 && tx < dest_w && ty >= 0 && ty < dest_h) {
                        img->at(tx, ty) = current;
                    }
                }
            }

            delete overlay_img;
            return img;
        }

        std::string add::toString() const {
            return "add " + filename + " "
                   + std::to_string(neutral_color.red()) + " "
                   + std::to_string(neutral_color.green()) + " "
                   + std::to_string(neutral_color.blue()) + " "
                   + std::to_string(x_offset) + " "
                   + std::to_string(y_offset);
        }
    }
}
