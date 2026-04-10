#include "../bmp_structs.hpp"
#include <cmath>

void rotate(BMPImage &image, int x1, int y1, int x2, int y2, int angle);
int deltaX (int angle, int x, int y);
int deltaY (int angle, int x, int y);