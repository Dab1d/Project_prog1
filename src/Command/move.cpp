#include "Command/move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <string>

namespace prog {
    namespace command {

        //Constructor: initializes the move offsets
        move::move(int offsetx, int offsety)
            : Command("move"), offsetx(offsetx), offsety(offsety) {}

        Image* move::apply(Image* img) {
            //Get image dimensions
            int w = img->width();
            int h = img->height();

            //Use pixel (0, 0) as fill color for empty areas
            Color fill = img->at(0, 0);
            Image* result = new Image(w, h, fill); //Create new image filled with base color

            //Loop through all rows
            for (int y = 0; y < h; ++y) {
                //Loop through all columns
                for (int x = 0; x < w; ++x) {
                    int newx = x + offsetx;
                    int newy = y + offsety;

                    //Copy pixel to new position if inside image bounds
                    if (newx >= 0 && newx < w && newy >= 0 && newy < h) {
                        result->at(newx, newy) = img->at(x, y);
                    }
                }
            }

            delete img; //Free original image memory
            return result; //Return moved image
        }

        //Return move command and offset values as string
        string move::toString() const {
            return "move " + to_string(offsetx) + " " + to_string(offsety);
        }
    }
}
