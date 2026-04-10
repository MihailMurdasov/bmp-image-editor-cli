#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "../bmp_structs.hpp"

void drawCircle(BMPImage& image, int center_x, int center_y, int r, int thickness, RGBTriple color, bool fill, RGBTriple fill_color);
void fillCircle(BMPImage& image, int center_x, int center_y, int r, RGBTriple color);