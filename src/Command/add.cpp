#include "Command/add.hpp"
#include "PNG.hpp"

namespace prog {
    namespace command {

        //Constructor: initializes file path, ignore color, and position
        add::add(const string& file_path, const Color& ignore_color, int posx, int posy)
            : Command("add"), file_path(file_path), ignore_color(ignore_color),
              posx(posx), posy(posy) {}

        Image* add::apply(Image* base_img) {
            Image* overlay_img = loadFromPNG(file_path); //Load overlay image

            //Get dimensions of base and overlay images
            int dest_w = base_img->width();
            int dest_h = base_img->height();
            int src_w = overlay_img->width();
            int src_h = overlay_img->height();

            //Loop through each row of overlay image
            for (int sy = 0; sy < src_h; ++sy) {
                //Loop through each column of overlay image
                for (int sx = 0; sx < src_w; ++sx) {
                    const Color& pixel = overlay_img->at(sx, sy); //Current overlay pixel

                    //Skip pixel if it matches the ignore color
                    if (pixel.red() == ignore_color.red() &&
                        pixel.green() == ignore_color.green() &&
                        pixel.blue() == ignore_color.blue()) {
                        continue;
                    }

                    //Target position in base image
                    int tx = posx + sx;
                    int ty = posy + sy;

                    //Copy pixel if inside base image bounds
                    if (tx >= 0 && tx < dest_w && ty >= 0 && ty < dest_h) {
                        base_img->at(tx, ty) = pixel;
                    }
                }
            }

            delete overlay_img; //Free memory
            return base_img;    //Return updated base image
        }

        //Return command as string with parameters
        string add::toString() const {
            return "add " + file_path + " "
                   + to_string(ignore_color.red()) + " "
                   + to_string(ignore_color.green()) + " "
                   + to_string(ignore_color.blue()) + " "
                   + to_string(posx) + " "
                   + to_string(posy);
        }
    }
}
