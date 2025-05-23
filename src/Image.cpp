#include "Image.hpp"

namespace prog {

    // Constructor that creates an image with dimensions (w x h), filled with a background color
    Image::Image(int w, int h, const Color &fill)
        : width_(w), height_(h), cor(h, std::vector<Color>(w, fill)) {
    }

    // Destructor
    Image::~Image() {
    }

    // Returns the width of the image
    int Image::width() const {
        return width_;
    }

    // Returns the height of the image
    int Image::height() const {
        return height_;
    }

    // Accessor that returns a reference to a pixel's color, allowing modification
    // x represents the column (horizontal axis)
    // y represents the row (vertical axis)

    Color &Image::at(int x, int y) {
		return cor[y][x];
    }
    // Read-only accessor for a pixel's color
    const Color &Image::at(int x, int y) const {
        return cor[y][x];
    }
}
