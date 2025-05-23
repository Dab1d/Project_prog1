#include "Command/Slide.hpp"
#include <sstream>

namespace prog {
    namespace command {

        //Constructor: initializes horizontal and vertical offsets
        Slide::Slide(int offsetx, int offsety)
            : Command("Slide"), offsetx(offsetx), offsety(offsety) {}

        //Get original image width and height
        Image* Slide::apply(Image* img) {
            int w = img->width();
            int h = img->height();

            //Create new empty image with same dimensions
            Image* result = new Image(w, h);

            //Loop through all pixels of original image
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    //Calculate new x and y positions with wrapping
                    int novox = (x + offsetx) % w;
                    int novoy = (y + offsety) % h;

                    //Fix negative wrap-around values
                    if (novox < 0){
                        novox += w;
                    }
                    if (novoy < 0){
                        novoy += h;
                    }

                    //Assign pixel color to new position in result image
                    result->at(novox, novoy) = img->at(x, y);
                }
            }

            delete img; //Free original image memory
            return result; //Return slid image
        }

        //Return the slide command and offset values as string
        string Slide::toString() const {
            return "Slide " + to_string(offsetx) + " " + to_string(offsety);
        }
    }
}
