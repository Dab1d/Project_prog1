//
// Created Eduardo Marques, adapted by José Proença on 06/04/2025 and by João Bispo on 15/04/2025.
//

// Project file headers
#include "ScrimParser.hpp"
#include "Image.hpp"
#include "PNG.hpp"
#include "Utils.h"
#include "Logger.hpp"

// C++ library headers
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

using std::string;
using std::vector;

static const string SCRIMS_FOLDER = "scrims";
static const string OUTPUT_FOLDER = "output";
static const string EXPECTED_FOLDER = "expected";


namespace prog {
  class TestDriver {
  public:
    explicit TestDriver(const string &root_path)
      : root_path(root_path) {
      string output_folder = root_path + "/" + OUTPUT_FOLDER;

      // Ensure output folder exists
      mkdir(output_folder);

      // Clean output folder
      delete_files(output_folder);
    }

  private:
    string root_path;
    int total_tests = 0;
    int passed_tests = 0;
    int failed_tests = 0;
    std::ofstream logfile = std::ofstream("test_log.txt");

    bool test_script(const string &id) {
      string scrim_file = root_path + "/" + SCRIMS_FOLDER + "/" + id + ".scrim";
      string out_file = root_path + "/" + OUTPUT_FOLDER + "/" + id + ".png";
      string exp_file = root_path + "/" + EXPECTED_FOLDER + "/" + id + ".png";
      string bad_file = root_path + "/" + OUTPUT_FOLDER + "/badfile-" + id + ".png";

      // Create parser
      ScrimParser parser;
      Scrim *scrim = parser.parseScrim(scrim_file); // get Scrim

      if (!scrim) {
        Logger::error("Scrim parse failed");
        return false;
      }

      prog::Image* img = scrim->run(); // run Scrim

      delete scrim; // Dispose of scrim
      delete img; // Dispose of the image

      std::ifstream bad_file_stream(bad_file);
      if (bad_file_stream.good()) {
        *Logger::err() << "Unexpected file produced: " << bad_file << std::endl;
        return false;
      }

      return comparePNG(exp_file, out_file);
    }

    void onTestBegin(const string &id) {
      total_tests++;

      *Logger::out() << '[' << total_tests << "] " << id << ": ";

      Logger::setOStream(logfile);
      Logger::setEStream(logfile);
      *Logger::out() << ">>> " << '[' << total_tests << "] " << id << " <<<\n";
    }

    void onTestCompletion(bool success) {
      Logger::setOStream(std::cout);
      Logger::setEStream(std::cerr);
      *Logger::out() << (success ? "pass" : "fail") << std::endl;
      if (success) {
        passed_tests++;
      } else {
        failed_tests++;
      }
    }

    void run_test(const string &script_id) {
      onTestBegin(script_id);

      const bool success = test_script(script_id);

      onTestCompletion(success);
    }

  public:
    static void color_tests() {
      const Color a(1, 2, 3);
      assert(a.red() == 1);
      assert(a.green() == 2);
      assert(a.blue() == 3);

      const Color b;
      assert(b.red() == 0);
      assert(b.green() == 0);
      assert(b.blue() == 0);

      const Color c(b);
      assert(c.red() == b.red());
      assert(c.green() == b.green());
      assert(c.blue() == b.blue());

      Color d(4, 5, 6);
      d.red() = 111;
      d.green() = 255;
      d.blue() = 33;
      assert(d.red() == 111);
      assert(d.green() == 255);
      assert(d.blue() == 33);
      *Logger::out() << "Color tests passed!" << std::endl;
    }

    void test_scrims(const string &spec) {
      const fs::path dir_path = root_path + "/" + SCRIMS_FOLDER;


      if (!fs::is_directory(dir_path)) {
        *Logger::err() << "Unable to open scrims directory (" << (root_path + "/" + SCRIMS_FOLDER) << ")!" << std::endl;
        return;
      }

      vector<string> scrims_to_execute;

      for (const auto &entry: fs::directory_iterator(dir_path)) {
        // Not a regular file, ignore (
        if (!entry.is_regular_file()) {
          continue;
        }

        // If given pattern is not in filename, ignore file
        string fname = entry.path().filename().string();
        if (fname.find(spec) == string::npos) {
          continue;
        }

        // Normalize path
        for (char &ch: fname) {
          if (ch == '\\') {
            ch = '/';
          }
        }

        // todo: only push if fname ends in .scrim
        string scrim = fname.substr(0, fname.find_last_of('.'));
        scrims_to_execute.push_back(scrim);
        // std::cout << "Adding file " << scrim<< " from '" << entry << "'\n";
      }

      if (scrims_to_execute.empty()) {
        *Logger::out() << "No scrims matched the spec: " << spec << std::endl;
        return;
      }
      sort(scrims_to_execute.begin(), scrims_to_execute.end());

      *Logger::out() << "== " << scrims_to_execute.size() << " tests to execute  ==" << std::endl;
      for (const string &id: scrims_to_execute) {
        run_test(id);
      }

      *Logger::out() << "== TEST EXECUTION SUMMARY ==" << std::endl
          << "Total tests: " << total_tests << std::endl
          << "Passed tests: " << passed_tests << std::endl
          << "Failed tests: " << failed_tests << std::endl;
    }
  };
}

int main(int argc, char **argv) {
  --argc;
  ++argv;
  prog::TestDriver driver(argc == 2 ? argv[1] : ".");
  string spec = argc >= 1 ? argv[0] : "";
  if (spec == "Color") {
    prog::TestDriver::color_tests();
  } else {
    driver.test_scrims(spec);
  }
  return 0;
}
