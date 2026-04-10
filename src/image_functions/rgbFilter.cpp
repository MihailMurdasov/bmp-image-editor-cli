#include "rgbFilter.hpp"

void 
rgbFilter(BMPImage& image, std::string component_name, int component_value) {
    
    if (component_name == "red") {
        for (int y = 0; y < image.infoHeader.biHeight; y++) {
            for (int x = 0; x < image.infoHeader.biWidth; x++) {
                image.pixelsArr[y][x].rgbRed = component_value;
            }
        }
    } else if (component_name == "green") {
        for (int y = 0; y < image.infoHeader.biHeight; y++) {
            for (int x = 0; x < image.infoHeader.biWidth; x++) {
                image.pixelsArr[y][x].rgbGreen = component_value;
            }
        }
    } else if (component_name == "blue") {
        for (int y = 0; y < image.infoHeader.biHeight; y++) {
            for (int x = 0; x < image.infoHeader.biWidth; x++) {
                image.pixelsArr[y][x].rgbBlue = component_value;
            }
        }
    }
}