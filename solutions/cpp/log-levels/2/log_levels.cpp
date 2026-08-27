#include <string>

namespace log_line {
std::string message(std::string line) {
  int separator = line.find(" ");
  return line.substr(separator + 1, line.length());
}

std::string log_level(std::string line) {
  int left_bracket = line.find("[");
  int right_bracket = line.find("]");
  return line.substr(left_bracket + 1, right_bracket - 1);
}

std::string reformat(std::string line) {
  int separator = line.find(" ");
  int left_bracket = line.find("[");
  int right_bracket = line.find("]");
  std::string error = line.substr(left_bracket + 1, right_bracket - 1);
  return line.substr(separator + 1, line.length()) + " (" + error + ")";
}
} // namespace log_line
