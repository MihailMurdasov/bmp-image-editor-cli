#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <getopt.h>
#include <algorithm>
#include <fstream>
#include <stdexcept>

#include "../bmp_structs.hpp"
#include "flagsProcessing.hpp"
#include "validateArgs.hpp"
#include "../image_functions/drawSquare.hpp"
#include "../image_functions/drawCircle.hpp"
#include "../image_functions/rotate.hpp"
#include "../image_functions/rgbFilter.hpp"
#include "../printInfo.hpp"
#include "../image_functions/outside_ornament.hpp"

void fullCheck(std::string firstFlag, std::unordered_map<std::string, std::string> argsMap);
void launchFunc(BMPImage& image, std::string funcName, std::unordered_map<std::string, std::string> argsMap);