#include "Command/chain.hpp"
#include "ScrimParser.hpp"
#include <algorithm>

namespace prog {
    namespace command {

        static int counter = 0;
        static vector<string> visitedList;

        chain::chain(vector<string> list) // constructor
            : Command("chain"), fileList(move(list)) {}

        Image* chain::apply(Image* src) {
            // clear visited each time we start an apply
            visitedList.clear();
            counter++;
            if (counter > 2) {
                counter -= 1;
                return src;
            }

            ScrimParser parser;
            // loop through each scrim file in chain
            for (auto& filename : fileList) {
                // skip if visited already
                if (find(visitedList.begin(), visitedList.end(), filename) != visitedList.end()){
                    continue;
                }
                visitedList.push_back(filename);

                ifstream file(filename);
                vector<Command*> commandList;
                string commandName;
                // read all commands in this scrim
                while (file >> commandName) {
                    // skip save and open commands
                    if (commandName == "save" || commandName == "open") {
                        string temp;
                        file >> temp;
                        continue;
                    }
                    // skip blank commands too
                    if (commandName == "blank") {
                        int w, h, r, g, b;
                        file >> w >> h >> r >> g >> b;
                        continue;
                    }

                    Command* cmd = parser.parse_command(commandName, file);
                    commandList.push_back(cmd);
                }

                // run the parsed commands
                Scrim* scrim = new Scrim(commandList);
                Image* result = scrim->run(src);
                delete scrim;
                // update src for the next scrim in the chain
                src = result;
            }
            counter--;
            return src;
        }
        // returns the command name
        string chain::toString() const {
            return name();
        }
    }
}