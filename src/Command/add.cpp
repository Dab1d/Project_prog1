// feito megaman dia 14 del5

#include "Command/add.hpp"
#include "PNG.hpp"

namespace prog {
    namespace command {

        add::add(const std::string& fname, const Color& bg_color, int dx, int dy)
            : Command("add"), fname(fname), bg_color(bg_color), dx(dx), dy(dy) {}

        Image* add::apply(Image* base_img) {
            Image* overlay_img = loadFromPNG(fname);

            const int dest_w = base_img->width();
            const int dest_h = base_img->height();
            const int src_w = overlay_img->width();
            const int src_h = overlay_img->height();

            for (int sy = 0; sy < src_h; ++sy) {
                for (int sx = 0; sx < src_w; ++sx) {

                    const Color& current = overlay_img->at(sx, sy);

                    // ve se a cor n é neutra
                    if (!(current.red() == bg_color.red() &&
                          current.green() == bg_color.green() &&
                          current.blue() == bg_color.blue())) {

                        int tx = dx + sx;
                        int ty = dy + sy;

                        // bascmente copia se tiver dentro da img destino
                        if ((tx | ty) >= 0 && tx < dest_w && ty < dest_h) {
                            base_img->at(tx, ty) = current;
                        }
                          }
                }
            }

            delete overlay_img;
            return base_img;
        }

        std::string add::toString() const {
            return "add " + fname + " " +
                   std::to_string(bg_color.red()) + " " +
                   std::to_string(bg_color.green()) + " " +
                   std::to_string(bg_color.blue()) + " " +
                   std::to_string(dx) + " " +
                   std::to_string(dy);
        }
    }
}