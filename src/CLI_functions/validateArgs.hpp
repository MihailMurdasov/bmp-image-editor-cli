#include <iostream>
#include <regex>
#include <unordered_map>
#include <string>
#include <vector>

#include "../printInfo.hpp"
#include "../bmp_structs.hpp"

std::vector<std::string> split(const std::string& str, const std::string& delim);
void isValidCoords(std::string coords, std::string arg);
void isValidColor(std::string color, std::string arg);
bool validateDrawSquare(std::string left_up, std::string side_size, std::string thickness, std::string color);
bool validateDrawSquare(std::string left_up, std::string side_size, std::string thickness, std::string color, std::string fill_color);
void validateRGBfilter(std::string component_name, std::string component_value);
void validateRotate(std::string left_up, std::string right_down, std::string angle);
bool validateCircle(std::string center, std::string radius, std::string thickness, std::string color);
bool validateCircle(std::string center, std::string radius, std::string thickness, std::string color, std::string fill_color);
void isCorrectArgs(std::string funcName, std::unordered_map<std::string, std::string> argsMap);
void validateOutside(std::string thickness, std::string color);