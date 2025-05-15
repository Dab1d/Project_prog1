//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"
#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Logger.hpp"
#include "Color.hpp"
#include "Command/Invert.hpp"
#include "Command/To_gray_scale.h"
#include "Command/Replace.hpp"
#include "Command/Crop.hpp"
#include "Command/Slide.hpp"
#include "Command/add.hpp"
#include "Command/move.hpp"
#include "Command/h_mirror.hpp"
#include "Command/v_mirror.hpp"


#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        if (command_name == "slide") {
            int x_offset,y_offset;
            input >> x_offset >> y_offset;
            return   new command::Slide(x_offset, y_offset);
        }

        if (command_name == "invert") {
            return new command::Invert();
        }

        if (command_name == "to_gray_scale") {
            return new command::To_gray_scale();
        }

        if (command_name == "replace") {
            int r1,g1,b1,r2,g2,b2;
            input >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
            return new command::Replace(r1,g1,b1,r2,g2,b2);
        }

        if (command_name == "add") {
            std::string fname;
            int red, green, blue;
            int pos_x = 0, pos_y = 0;
            input >> fname >> red >> green >> blue >> pos_x >> pos_y;
            Color filter_color{
                static_cast<rgb_value>(red),
                static_cast<rgb_value>(green),
                static_cast<rgb_value>(blue)
            };
            auto* cmd = new command::add(fname, filter_color, pos_x, pos_y);
            return cmd;
        }

        if (command_name == "move") {
            int offsetx, offsety;
            input >> offsetx >> offsety;
            return new command::move(offsetx, offsety);
        }

        if (command_name == "h_mirror") {
            return new command::h_mirror();
        }

        if (command_name == "v_mirror") {
            return new command::v_mirror();
        }

        // TODO: implement cases for the new commands

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
