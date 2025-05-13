//
// Created by 2006d on 13/05/2025.
//

#ifndef TO_GRAY_SCALE_H
#define TO_GRAY_SCALE_H

#include "Image.hpp"

#include <string>

namespace prog {
    class to_gray_scale {
    public:
        (std::string to_gray_scale);

        virtual ~to_gray_scale() = 0;

        /**
         * Applies this command to an image.
         *
         * @param img
         * @return the image after the command (can be the same pointer or a new one).
         * If a new pointer is returned, the previous one is deleted.
         */
        virtual Image *apply(Image *img) = 0;

        /**
         *
         * @return string representation of this command, for printing
         */
        virtual std::string toString() const;

        std::string name() const;


    };
}

std::ostream &operator<<(std::ostream &output, const prog::Command &command);

#endif //TO_GRAY_SCALE_H
