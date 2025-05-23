#include "Command.hpp" //Includes the base Command class definition
#include "Command/fill.h" //Includes the header for the fill command
#include <sstream> //Includes the sstream library for string stream functionality

namespace prog {
    namespace command {

        //Constructor for the fill command, initializes position, dimensions, and color components
        fill::fill(int x, int y, int w, int h, rgb_value r, rgb_value g, rgb_value b) : Command("fill"), x_(x), y_(y), w_(w), h_(h), r_(r), g_(g), b_(b) {}

        fill::~fill() {} //Destructor for the fill command

        //Applies the fill command to the given image
        Image* fill::apply(Image* img) {

            //Get image dimensions (width and height)
            int largura = img->width();
            int altura = img->height();

            //Create a Color object with the specified RGB values
            Color c(r_, g_, b_);

            //Calculate the fill area limits
            int x_limite = x_ + w_;
            int y_limite = y_ + h_;

            //Iterate over every column in the specified rectangular region
            for (int y = y_; y < y_limite; y++) {
                //Iterate over every line in the specified rectangular region
                for (int x = x_; x < x_limite; x++) {
                    if (x >= 0 && x < largura && y >= 0 && y < altura) //Check if (x, y) is within image bounds
                            img->at(x, y) = c; //Set the pixel color to the specified color
                }
            }
            //Return the modified image
            return img;
        }
        //Returns a string representation of the command
        std::string fill::toString() const {
            std::ostringstream ss; //Create a string stream
            ss << name(); //Add the command name to the stream
            return ss.str(); //Return the string
        }
    }
}
