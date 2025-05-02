//
// Created by José Proença on 16/04/2025.
//
#include <iostream>
#include <fstream>
#include <string>

namespace prog {
  class Logger {
  public:
    Logger(const Logger&) = delete; // forbid this constructor
    Logger& operator=(const Logger&) = delete; // forbid assignments to loggers

    static Logger& getInstance();

    // Set custom output stream (e.g., file or std::cerr)
    static void setEStream(std::ostream& stream);
    static void setOStream(std::ostream& stream);

    // Log a message to the current output stream
    static void log(const std::string& message);
    static void error(const std::string& message);

    static std::ostream* out();
    static std::ostream* err();

  private:
    Logger() : out_(&std::cout), err_(&std::cerr) {}  // Default to std::cout and std::cerr
    ~Logger() = default;

    std::ostream* out_;
    std::ostream* err_;
    std::string prefix;
  };
}