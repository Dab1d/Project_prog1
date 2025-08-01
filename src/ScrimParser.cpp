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
#include "Command/crop.hpp"
#include "Command/Slide.hpp"
#include "Command/add.hpp"
#include "Command/move.hpp"
#include "Command/h_mirror.hpp"
#include "Command/v_mirror.hpp"
#include "Command/fill.h"
#include "Command/scaleup.hpp"
#include "Command/rotate_left.h"
#include "Command/rotate_right.h"
#include "Command/resize.h"
#include "Command/chain.hpp"


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
            int offsetx, offsety;
            input >> offsetx >> offsety;
            return   new command::Slide(offsetx, offsety);
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
            string fname;
            int red, green, blue, posx, posy;
            input >> fname >> red >> green >> blue >> posx >> posy;
            Color filter_color{
                static_cast<rgb_value>(red),
                static_cast<rgb_value>(green),
                static_cast<rgb_value>(blue)
            };
            return new command::add(fname, filter_color, posx, posy);
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

        if (command_name == "rotate_left") {
            return new command::rotate_left();
        }

        if (command_name == "fill") {
            int x, y, w, h, r, g, b;
            input >> x >> y >> w >> h >> r >> g >> b;
            return new command::fill(x, y, w, h, r, g, b);
        }

        if (command_name == "rotate_right") {
            return new command::rotate_right();
        }

        if (command_name == "scaleup") {
            int w, h;
            input >> w >> h;
            return new command::scaleup(w, h);
        }

        if (command_name == "crop") {
            int x, y ,w ,h;
            input >> x >> y >> w >> h;
            return new command::crop(x,y,w,h);
        }

        if (command_name == "resize") {
            int x, y ,w ,h;
            input >> x >> y >> w >> h;
            return new command::resize(x,y,w,h);
        }

		if (command_name == "chain") {
    		// input variable and list of inputs
    		string x;
    		vector<string> list;
    		// reads the input and adds it to the list
    		while (input >> x && x != "end") {
        		list.push_back(x);
    		}
    		return new command::chain(list);
		}

        // TODO: implement cases for the new commands

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
