//
// Created by José Proença on 16/04/2025.
//
#include "Logger.hpp"

namespace prog {
  Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
  }

  void Logger::setEStream(std::ostream& stream) {
    Logger::getInstance().err_ = &stream;
  }

  void Logger::setOStream(std::ostream& stream) {
    Logger::getInstance().out_ = &stream;
  }

  void Logger::log(const std::string& message) {
    std::ostream* out = getInstance().out_;
    if (out) {
      (*out) << getInstance().prefix << message << std::endl;
    }
  }

  void Logger::error(const std::string& message) {
    std::ostream* err = getInstance().err_;
    if (err) {
      (*err) << getInstance().prefix << message << std::endl;
    }
  }

  std::ostream* Logger::out() {
    return &(*getInstance().out_ << getInstance().prefix);
  }

  std::ostream* Logger::err() {
    return &(*getInstance().err_ << getInstance().prefix);
  }


}