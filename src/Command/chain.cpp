// done by tiago

#include "Command/chain.hpp"
#include "ScrimParser.hpp"
#include "Scrim.hpp"

namespace prog {
    namespace command {

        chain::chain(vector<string> list)
            : Command("chain"), fileList(list) {}

        Image* chain::apply(Image* src) {
            ScrimParser parser; // to read .scrim files
            for (ler cada ficheiro e executar as funcoes) {}
        }
    }
}