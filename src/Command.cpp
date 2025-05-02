//
// Created by JBispo on 05/04/2025.
//
#include "Command.hpp"

namespace prog {
    Command::Command(std::string command_name) : command_name(command_name) {
    }

    Command::~Command() {
    }

    std::string Command::name() const {
        return command_name;
    }

    /**
     * Default implementation that just returns the name.
     *
     * @return
     */
    std::string Command::toString() const {
        return command_name;
    }
}

std::ostream &operator<<(std::ostream &output, const prog::Command &command) {
    output << command.toString();
    return output;
}
