#include "Scrim.hpp"
#include "ScrimParser.hpp"
#include "Image.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv) {
    if (argc == 1) {
        cout << "Usage: " << argv[0] << " scrim1 scrim2 ..." << endl;
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        cout << "==> Running scrim: " << argv[i] << endl;
        // Create parser
        prog::ScrimParser parser;

        prog::Scrim* scrim = parser.parseScrim(argv[i]); // get Scrim

        if (scrim == nullptr) {
            cout << "Error parsing scrim: " << argv[i] << endl;
            continue;
        }

        prog::Image* img = scrim-> run(); // run Scrim
        cout << endl;

        delete scrim; // Dispose of the scrim
        delete img; // Dispose of the image
    }
    cout << "==> Done :) " << endl;
    return 0;
}