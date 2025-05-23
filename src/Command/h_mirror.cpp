#include "Command.hpp" // Includes the base Command class header
#include "Command/h_mirror.hpp" // Includes the header for the h_mirror command

namespace prog {
    namespace command {

        h_mirror::h_mirror() : Command("h_mirror") {} // Constructor for the h_mirror class, sets the command name
        h_mirror::~h_mirror(){} // Destructor for the h_mirror class
        Image *h_mirror::apply(Image *img) { // Applies the horizontal mirror transformation to the image
            // Get image dimensions (width and height)
            int largura = img->width();
            int altura = img->height();
            Image *newImg = new Image(largura, altura); // Create a new image with the same dimensions
            // Iterate over each row (y-axis)
            for (int y = 0; y < altura; y++) {
                // Iterate over each column (x-axis)
                for (int x = 0; x < largura; x++) {
                    // Set pixel (x, y) in new image to the horizontally mirrored pixel from original image
                    newImg->at(x, y) = img->at(largura - x - 1, y);
                }
            }
            delete img; // Delete the original image to free memory
            return newImg; // Return the new horizontally mirrored image
        }
    }
}
