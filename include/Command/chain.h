#ifndef CHAIN_COMMAND_HEADER
#define CHAIN_COMMAND_HEADER

#include "Command.hpp"
#include <string>
#include <vector>

using namespace std;

namespace prog {
    namespace command {
        class chain : public Command {
        public:

            explicit chain(vector<string> list);

            ~chain();

            Image* apply(Image* src) override;

            string toString() const override;

        private:
            vector<string> fileList;
        };
    }
}
#endif