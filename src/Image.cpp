#include "Image.hpp"

namespace prog {

    // Construtor que gera uma imagem w por h com uma cor de fundo
    Image::Image(int w, int h, const Color &fill):
     width_(w),height_(h), cor(h, std::vector<Color>(w, fill))  {}

    //Destructor
    Image::~Image() {
    }

    //retorna o valor largura da imagem
    int Image::width() const {
        return width_;
    }
    //retorna o valor da altura da imagem
    int Image::height() const {
        return height_;
    }

    // Função que acede ao valor da cor, podendo ser alterado(mutado)
    //
    //--> x representa as colunas(horizontal) e y as linhas(vertical)
    //
    //--> e, por definição, o acesso à matriz 2D é feito primeiro ás linhas e depois ás colunas (cor[y][x])

    Color &Image::at(int x, int y) {
		return cor[y][x];
    }
    //Função apenas de leitura do valor da cor
    const Color &Image::at(int x, int y) const {
        return cor[y][x];
    }
}
