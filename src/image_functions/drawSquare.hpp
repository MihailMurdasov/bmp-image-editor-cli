#include "../bmp_structs.hpp"
#include <iostream>

void draw_square(BMPImage& image, int x, int y, int side_size, int thickness, RGBTriple color, bool fill, RGBTriple fill_color);
void draw_line(BMPImage& image, int x, int y, int x1, int y1, int thickness, RGBTriple color);