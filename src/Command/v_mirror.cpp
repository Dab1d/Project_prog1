#include "Command.hpp" //Includes the base Command class header
#include "Command/v_mirror.hpp" //Includes the header for the v_mirror command
#include <sstream> //Includes the sstream library for string stream functionality

namespace prog {
    namespace command {
        v_mirror::v_mirror() : Command("v_mirror") {} //Contructor for the v_mirror class, sets the command name to "v_mirror"

        v_mirror::~v_mirror(){} //Destructor for the v_mirror class

        Image *v_mirror::apply(Image *img) { //Applies the vertical mirror transformation to the image

            //Get image dimensions (width and height)
            int largura = img->width();
            int altura = img->height();
            Image *newImg = new Image(largura, altura); //Create a new image with the same dimensions as the original

            //Iterate over every column (x-axis)
            for (int x = 0; x < largura; x++) {
                //iterates over every line (y-axis)
                for (int y = 0; y < altura; y++) {
                    //Set pixel (x,y) in new image to the vertically mirrorred pixel from the original image
                    newImg->at(x,y) = img->at(x,altura-1-y);
                }
            }
            delete img; //Delete original image to free memory
            return newImg; //Return the vertically mirrorred image
        }
        //Returns a string representation of the command
        std::string v_mirror::toString() const {
            std::ostringstream ss; //Create a string stream
            ss << name(); //Add the command name to the stream
            return ss.str(); //Return the string
        }
    }
}
