#include "outside_ornament.hpp"

void outside_ornament(BMPImage& image, int thickness, RGBTriple color) {
    for (int i = 0; i < thickness; i++) {
        std::vector<RGBTriple> vec(image.infoHeader.biWidth, color);
        image.pixelsArr.insert(image.pixelsArr.begin(), vec);
        image.pixelsArr.push_back(vec);
    }
    image.infoHeader.biHeight += thickness*2;

    for (int i = 0; i < image.infoHeader.biHeight; i++) {
        for (int j = 0; j < thickness; j++) {
            image.pixelsArr[i].insert(image.pixelsArr[i].begin(), color);
            image.pixelsArr[i].push_back(color);
        }
    }
    image.infoHeader.biWidth += thickness*2;
}