#ifndef __prog_Script_hpp__
#define __prog_Script_hpp__

#include "Command.hpp"
#include "Image.hpp"
#include <string>
#include <fstream>

namespace prog {
    class Scrim {
    public:
        Scrim(std::vector<Command *> &commands);

        ~Scrim();


        /**
         * Runs this pipeline starting with the given image.
         *
         * @param img
         * @return the image created/transformed by this pipeline
         */
        Image *run(Image *img);

        /**
         * Runs this pipeline without a starting image.
         *
         * @return the image created by this pipeline
         */
        Image *run();

        /**
         * Provides a reference for the vector of commands.
         *
         * @return a reference to the commends
         */
        std::vector<Command *> getCommands() const;

    private:
        // Commands
        std::vector<Command *> commands;

    private:
        // Private functions
        // implement just 3 commands: blank, open, save.
    };
}
#endif

