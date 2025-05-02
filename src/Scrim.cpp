//
// Created by JBispo on 05/04/2025.
//
#include "Scrim.hpp"
#include "Logger.hpp"

using prog::Command;

namespace prog {
    Scrim::Scrim(std::vector<Command *> &commands) : commands(commands) {
    }

    Scrim::~Scrim() {
        // Deallocate each command
        for (Command *c: commands) {
            delete c;
        }
    };

    Image *Scrim::run(Image *img) {
        for (Command *c: commands) {
            *Logger::out() << "Applying command '" << c->toString() << "'\n";
            img = c->apply(img);
        }

        return img;
    }

    Image *Scrim::run() {
        return this->run(nullptr);
    }

    std::vector<Command *> Scrim::getCommands() const {
        return commands;
    }
}
