#include "rotate.hpp"

int 
deltaX (int angle, int x, int y) {

    if (angle == 90) {
        if (x%2 == 0 && y%2 == 0) return 0;
        if (x%2 != 0 && y%2 != 0) return 0;
        if (x%2 == 0 && y%2 != 0) return 0;
        if (x%2 != 0 && y%2 == 0) return 0; //
    }

    if (angle == 180) {
        if (x%2 != 0 && y%2 == 0) return 0;
        if (x%2 != 0 && y%2 != 0) return 0;
        if (x%2 == 0 && y%2 != 0) return -1;
        if (x%2 == 0 && y%2 == 0) return -1;
    }

    if (angle == 270) {
        if (x%2 != 0 && y%2 != 0) return 0;
        if (x%2 != 0 && y%2 == 0) return -1;
        if (x%2 == 0 && y%2 == 0) return -1;
        if (x%2 == 0 && y%2 != 0) return 0; //
    }

    return 0;

}

int 
deltaY (int angle, int x, int y) {

    if (angle == 90) {
        if (x%2 == 0 && y%2 == 0) return -1;
        if (x%2 != 0 && y%2 != 0) return 0;
        if (x%2 == 0 && y%2 != 0) return -1;
        if (x%2 != 0 && y%2 == 0) return 0; //
    }

    if (angle == 180) {
        if (x%2 != 0 && y%2 == 0) return -1;
        if (x%2 != 0 && y%2 != 0) return 0;
        if (x%2 == 0 && y%2 != 0) return 0;
        if (x%2 == 0 && y%2 == 0) return -1;
    }

    if (angle == 270) {
        if (x%2 != 0 && y%2 != 0) return 0;
        if (x%2 != 0 && y%2 == 0) return 0;
        if (x%2 == 0 && y%2 == 0) return 0;
        if (x%2 == 0 && y%2 != 0) return 0; //
    }

    return 0;

}

void 
rotate(BMPImage &image, int x, int y, int x1, int y1, int angle) {
    
    if (angle % 360 == 0) {
        return;
    }

    std::vector<std::vector<RGBTriple>> new_elem = image.pixelsArr;
 
    double radians = (angle * M_PI/180);
    
    if (x < 0) {
        x = 0;
    } else if (x >= image.infoHeader.biWidth) {
        x = image.infoHeader.biWidth;
    }

    if (y < 0) {
        y = 0;
    } else if (y >= image.infoHeader.biHeight) {
        y = image.infoHeader.biHeight;
    }

    if (x1 < 0) {
        x1 = 0;
    } else if (x1 >= image.infoHeader.biWidth) {
        x1 = image.infoHeader.biWidth;
    }

    if (y1 < 0) {
        y1 = 0;
    } else if (y1 >= image.infoHeader.biHeight) {
        y1 = image.infoHeader.biHeight;
    }

    int cx = (x + x1) / 2;
    int cy = (y + y1) / 2;

    if (angle == 180) {
        for (int i = y; i < y1; i++) {
            for (int j = x; j < x1; j++) {
                if (i < 0 || j < 0 || i >= image.infoHeader.biHeight || j >= image.infoHeader.biWidth) {
                    continue;
                }

                int dx = deltaX(angle, x1 - x, y1 - y);
                int dy = deltaY(angle, x1 - x, y1 - y);

                double i_old = (cy - i);
                double j_old = (cx - j);

                if (cy + round(i_old) + dy >= 0 && cy + round(i_old) + dy < image.infoHeader.biHeight &&
                    cx + round(j_old) + dx >= 0 && cx + round(j_old) + dx < image.infoHeader.biWidth) {
                    image.pixelsArr[i][j] = new_elem[cy + round(i_old) + dy][cx + round(j_old) + dx];
                }
            }
        }

        return;
    }

    for (int i = y; i < y1; i++) {
        for (int j = x; j < x1; j++) {
            if (i < 0 || j < 0 || i >= image.infoHeader.biHeight || j >= image.infoHeader.biWidth) {
                continue;
            }

            int dx = deltaX(angle, x1 - x, y1 - y);
            int dy = deltaY(angle, x1 - x, y1 - y);

            double i_old = (cy - i);
            double j_old = (cx - j);

            double i_new = j_old * sin(radians) + i_old * cos(radians) + dy;
            double j_new = j_old * cos(radians) - i_old * sin(radians) + dx;

            if (cy + round(i_new) >= 0 && cy + round(i_new) < image.infoHeader.biHeight &&
                cx + round(j_new) >= 0 && cx + round(j_new) < image.infoHeader.biWidth) {
                image.pixelsArr[round(i_new) + cy][round(j_new) + cx] = new_elem[i][j];
            }
        }
    }

}
