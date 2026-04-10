#include "drawCircle.hpp"

void 
fillCircle(BMPImage& image, int center_x, int center_y, int r, RGBTriple color) {

    if (r == 1) {
        if (center_y + 1 >= 0 && center_y + 1 < image.infoHeader.biHeight &&
            center_x >= 0 && center_x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y + 1][center_x] = color;
        }
        if (center_y - 1 >= 0 && center_y - 1 < image.infoHeader.biHeight &&
            center_x >= 0 && center_x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y - 1][center_x] = color;
        }
        if (center_y >= 0 && center_y < image.infoHeader.biHeight &&
            center_x - 1 >= 0 && center_x - 1 < image.infoHeader.biWidth) {

            image.pixelsArr[center_y][center_x - 1] = color;
        }
        if (center_y >= 0 && center_y < image.infoHeader.biHeight &&
            center_x + 1 >= 0 && center_x + 1 < image.infoHeader.biWidth) {

            image.pixelsArr[center_y][center_x + 1] = color;
        } 
        if (center_y >= 0 && center_y < image.infoHeader.biHeight &&
            center_x >= 0 && center_x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y][center_x] = color;
        }   

        return;       
    }

    int x = 0;
    int y = r;
    int delta = 3 - 2 * y;
    
    while (y >= x) {
        if (center_y + y >= 0 && center_y + y < image.infoHeader.biHeight &&
            center_x + x >= 0 && center_x + x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y + y][center_x + x] = color;
        }
        if (center_y - y >= 0 && center_y - y < image.infoHeader.biHeight &&
            center_x + x >= 0 && center_x + x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y - y][center_x + x] = color;
        }
        if (center_y + y >= 0 && center_y + y < image.infoHeader.biHeight &&
            center_x - x >= 0 && center_x - x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y + y][center_x - x] = color;
        }
        if (center_y - y >= 0 && center_y - y < image.infoHeader.biHeight &&
            center_x - x >= 0 && center_x - x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y - y][center_x - x] = color;
        }
        if (center_y + x >= 0 && center_y + x < image.infoHeader.biHeight &&
            center_x + y >= 0 && center_x + y < image.infoHeader.biWidth) {

            image.pixelsArr[center_y + x][center_x + y] = color;
        }
        if (center_y - x >= 0 && center_y - x < image.infoHeader.biHeight &&
            center_x + y >= 0 && center_x + y < image.infoHeader.biWidth) {

            image.pixelsArr[center_y - x][center_x + y] = color;
        }
        if (center_y + x >= 0 && center_y + x < image.infoHeader.biHeight &&
            center_x - y >= 0 && center_x - y < image.infoHeader.biWidth) {

            image.pixelsArr[center_y + x][center_x - y] = color;
        }
        if (center_y - x >= 0 && center_y - x < image.infoHeader.biHeight &&
            center_x - y >= 0 && center_x - y < image.infoHeader.biWidth) {
                
            image.pixelsArr[center_y - x][center_x - y] = color;
        }

        delta += delta < 0 ? 4 * x + 6 : 4 * (x - y--) + 10;
        ++x;
    }

    for (int y = -r; y <= r; y++) {
        if ((center_y + y)<0 || (center_y + y)>=image.infoHeader.biHeight) {
            continue;
        }
        for (int x = -r; x <= r; x++) {
            if (((center_x+x)>=0) && ((center_x+x)<image.infoHeader.biWidth) && (x * x + y * y <= r * r)) {
                image.pixelsArr[center_y + y][center_x + x] = color;
            }
        }
    }
}


void 
drawCircle(BMPImage& image, int center_x, int center_y, int r, int thickness, RGBTriple color, bool fill, RGBTriple fill_color) {

    int x = 0;
    int radius;
    int y = r;
    int delta = 1 - 2 * r;
    int error = 0;

    if (thickness % 2 == 0) {
        radius = thickness / 2;
    } else if (thickness == 1) {
        radius = 0;
    } else {
        radius = (thickness + 1) / 2;
    }

    if (fill == true) {
        fillCircle(image, center_x, center_y, r, fill_color);
    }

    if (r == 1) {
        if (center_y + 1 >= 0 && center_y + 1 < image.infoHeader.biHeight &&
            center_x >= 0 && center_x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y + 1][center_x] = color;
        }
        if (center_y - 1 >= 0 && center_y - 1 < image.infoHeader.biHeight &&
            center_x >= 0 && center_x < image.infoHeader.biWidth) {

            image.pixelsArr[center_y - 1][center_x] = color;
        }
        if (center_y >= 0 && center_y < image.infoHeader.biHeight &&
            center_x - 1 >= 0 && center_x - 1 < image.infoHeader.biWidth) {

            image.pixelsArr[center_y][center_x - 1] = color;
        }
        if (center_y >= 0 && center_y < image.infoHeader.biHeight &&
            center_x + 1 >= 0 && center_x + 1 < image.infoHeader.biWidth) {

            image.pixelsArr[center_y][center_x + 1] = color;
        }  

        return;       
    }

    while (y >= x) {

        fillCircle(image, center_x + x, center_y + y, radius, color);
        fillCircle(image, center_x + x, center_y - y, radius, color);
        fillCircle(image, center_x - x, center_y + y, radius, color);
        fillCircle(image, center_x - x, center_y - y, radius, color);
        fillCircle(image, center_x + y, center_y + x, radius, color);
        fillCircle(image, center_x + y, center_y - x, radius, color);
        fillCircle(image, center_x - y, center_y + x, radius, color);
        fillCircle(image, center_x - y, center_y - x, radius, color);
        
        error = 2 * (delta + y) - 1;
        if ((delta < 0) && (error <= 0)) {
            delta += 2 * ++x + 1;
            continue;
        }
        if ((delta > 0) && (error > 0)) {
            delta -= 2 * --y + 1;
            continue;
        }

        delta += 2 * (++x - --y);
    }
}