// feito pelo MegaMan no dia 14 de maio

#include "Command/add.hpp"
#include "PNG.hpp"

namespace prog {
    namespace command {

        add::add(const std::string& file_path, const Color& ignore_color, int pos_x, int pos_y)
            : Command("add"), file_path(file_path), ignore_color(ignore_color),
              pos_x(pos_x), pos_y(pos_y) {}

        Image* add::apply(Image* base_img) {
            Image* overlay_img = loadFromPNG(file_path);

            int dest_w = base_img->width();
            int dest_h = base_img->height();
            int src_w = overlay_img->width();
            int src_h = overlay_img->height();

            for (int sy = 0; sy < src_h; ++sy) {
                for (int sx = 0; sx < src_w; ++sx) {
                    const Color& pixel = overlay_img->at(sx, sy);

                    if (pixel.red() == ignore_color.red() &&
                        pixel.green() == ignore_color.green() &&
                        pixel.blue() == ignore_color.blue()) {
                        continue;
                        }

                    int tx = pos_x + sx;
                    int ty = pos_y + sy;

                    if (tx >= 0 && tx < dest_w && ty >= 0 && ty < dest_h) {
                        base_img->at(tx, ty) = pixel;
                    }
                }
            }
            delete overlay_img;
            return base_img;
        }
        std::string add::toString() const {
            return "add " + file_path + " "
                   + std::to_string(ignore_color.red()) + " "
                   + std::to_string(ignore_color.green()) + " "
                   + std::to_string(ignore_color.blue()) + " "
                   + std::to_string(pos_x) + " "
                   + std::to_string(pos_y);
        }
    }
}