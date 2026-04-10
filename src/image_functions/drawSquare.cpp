#include "drawSquare.hpp"
#include "drawCircle.hpp"

void 
draw_square(BMPImage &image, int x, int y, int side_size, int thickness, RGBTriple color, bool fill, RGBTriple fill_color) {

    if (fill == true) {
        for (int i = y + 1; i < y + side_size; i++) {
            for (int j = x + 1; j < x + side_size; j++) {
                if (i < 0 || j < 0 || i >= image.infoHeader.biHeight || j >= image.infoHeader.biWidth) {
                    continue;
                }
                image.pixelsArr[i][j] = fill_color;
            }
        }
    }
    
    if (thickness == 1) {
        for (int i = y; i < y + side_size; i++) {
            if (i >= 0 && i < image.infoHeader.biHeight && 
                x >= 0 && x < image.infoHeader.biWidth) {

                image.pixelsArr[i][x] = color;
            }

            if (i >= 0 && i < image.infoHeader.biHeight && 
                x + side_size >= 0 && x + side_size < image.infoHeader.biWidth) {

                image.pixelsArr[i][x + side_size] = color;
            }
        }

        for (int i = x; i < x + side_size; i++) {
            if (y >= 0 && y < image.infoHeader.biHeight && 
                i >= 0 && i < image.infoHeader.biWidth) {

                image.pixelsArr[y][i] = color;
            }

            if (i >= 0 && i < image.infoHeader.biWidth && 
                y + side_size > 0 && y + side_size < image.infoHeader.biHeight) {

                image.pixelsArr[y + side_size][i] = color;
            }
        }

        for (int i = y; i < y + side_size; i++) {
            for (int j = x; j < x + side_size; j++) {
                if (i - y == j - x) {

                    if (i >= 0 && i < image.infoHeader.biHeight &&
                        j >= 0 && j < image.infoHeader.biWidth) {
                            image.pixelsArr[i][j] = color;
                        }

                    if (i >= 0 && i < image.infoHeader.biHeight &&
                        side_size + 2 * x - j < image.infoHeader.biWidth && side_size + 2 * x - j >= 0) {
                            image.pixelsArr[i][side_size + 2 * x - j] = color;
                    }
                
                }
            }
        }

        return;
    }

    int radius = 0;
    if (thickness % 2 == 0) {
        radius = thickness / 2;
    } else if (thickness == 1) {
        radius = 0;
    } else {
        radius = (thickness + 1) / 2;
    }

    for (int i = x; i < x + side_size; i++) {
        if (i < 0 || i >= image.infoHeader.biWidth) {
            continue;
        }
        fillCircle(image, i, y, radius, color);
        fillCircle(image, i, y + side_size, radius, color);
    }

    for (int i = y; i < y + side_size; i++) {
        if (i < 0 || i >= image.infoHeader.biHeight) {
            continue;
        }
        fillCircle(image, x, i, radius, color);
        fillCircle(image, x + side_size, i, radius, color);
    }

    for (int i = y; i < y + side_size; i++) {
        for (int j = x; j < x + side_size; j++) {
            if (i - y == j - x) {
                fillCircle(image, j, i, radius, color);
                fillCircle(image, side_size + 2 * x - j, i, radius, color);
            }
        }
    }
}

void draw_line(BMPImage& image, int x, int y, int x1, int y1, int thickness, RGBTriple color){
  	int delta_x = abs(x1 - x);
  	int delta_y = abs(y1 - y);
  	int sign_x = x < x1 ? 1 : -1;
  	int sign_y = y < y1 ? 1 : -1;
  	int error = delta_x - delta_y, error2;
    /*int radius;
    if (thickness % 2 == 0) {
        radius = thickness / 2;
    } else if (thickness == 1) {
        radius = 0;
    } else {
        radius = (thickness + 1) / 2;
    }*/
	
  	while (x != x1 || y != y1) {
        if (y >= 0 && y < image.infoHeader.biHeight &&
            x >= 0 && x < image.infoHeader.biWidth) {
            if (thickness == 1) { 
                image.pixelsArr[y][x] = color;
            } else { 
                fillCircle(image, x, y, thickness/2 , color);
            }
            
            error2 = 2 * error;
            if (error2 > -delta_y) {
                error -= delta_y;
                x += sign_x;
            }
            if (error2 < delta_x) {
                error += delta_x;
                y += sign_y;
            }
        }
	}
}