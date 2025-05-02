#ifndef PROJECT_SCRIPTPARSER_H
#define PROJECT_SCRIPTPARSER_H

#include "Scrim.hpp"
#include <iostream>

namespace prog {
    class ScrimParser {
    public:
        ScrimParser();

        ~ScrimParser();


        /**
         * Base method that parses an input script, from a generic input stream.
         *
         * @param input
         * @return a **new** ImagePipeline built from the script defined in the input stream
         */
        Scrim *parseScrim(std::istream &input);

        /**
         * Helper method that accepts a file.
         *
         * @param filename
         * @return a **new** ImagePipeline built from the script defined in the given file
         */
        Scrim *parseScrim(const std::string &filename);

        Command *parse_command(std::string command_name, std::istream &istream);
    };
}

#endif //PROJECT_SCRIPTPARSER_H
