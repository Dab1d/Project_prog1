#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>

    namespace prog {
        class Image {

        public:

            //Constructor que cria uma imagem w x h,
            //preenchendo-a com uma cor
            Image(int w, int h, const Color &fill = {255, 255, 255});

            //Destructor
            ~Image();
            // Retorna a largura (nº de linhas)
            int width() const;

            // Retorna a altura (nº de colunas)
            int height() const;

            //Pixel mutável
            Color &at(int x, int y);

            //Pixel Imutavel
            const Color &at(int x, int y) const;

        private:

            int width_;
            int height_;
            //Matriz 2D que contém a cor de cada pixel
            std::vector<std::vector<Color>> cor;
        };
}
#endif
