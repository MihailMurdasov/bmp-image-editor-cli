#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <getopt.h>
#include <algorithm>

#include "../bmp_structs.hpp"
#include "validateArgs.hpp"
#include "../image_functions/drawSquare.hpp"
#include "../printInfo.hpp"

std::string getFuncName(std::unordered_map<std::string, std::string> argsMap);
std::unordered_map<std::string, std::string> getArgs(int argc, char** argv);
void isCorrectFlags(std::vector<std::string> flags, std::unordered_map<std::string, std::string> argsMap);