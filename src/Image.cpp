#include "Image.hpp"

namespace prog {

    // Construtor que gera uma imagem w por h com uma cor de fundo
    Image::Image(int w, int h, const Color &fill):
     width_(w),height_(h), cor(h, std::vector<Color>(w, fill))  {}

    //Destructor
    Image::~Image() {
    }

    //
    int Image::width() const {
        return width_;
    }

    int Image::height() const {
        return height_;
    }


    //Função que acessa o valor da cor, podendo ser alterado(mutado)
    Color &Image::at(int x, int y) {
		return cor[y][x];
    }
    //Função apenas de leitura do valor da cor
    const Color &Image::at(int x, int y) const {
        return cor[y][x];
    }
}
