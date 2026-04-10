#include "writeBmp.hpp"

void 
writeBmp(const BMPImage& image, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);

    try {
        if (!file.is_open()) {
            throw std::runtime_error("cw: Невозможно открыть файл: " + filename);
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(41);
    }
    file.write((char*)&image.fileHeader, sizeof(BMPFileHeader));

    file.write((char*)&image.infoHeader, sizeof(BMPInfoHeader));

    file.seekp(image.fileHeader.bfFileOffsetToPixelArray, std::ios::beg);

    unsigned int padding = (image.infoHeader.biWidth * sizeof(RGBTriple)) % 4;
    if (padding) padding = 4 - padding;

    for (int i = image.infoHeader.biHeight - 1; i >= 0; i--) {
        
        file.write((char*)image.pixelsArr[i].data(), (image.pixelsArr[i].size())*sizeof(RGBTriple));
        for (int j = 0; j < padding; j++) {
            char zero = 0;
            file.write((char*)&zero, 1);
        }
    }


    file.close();
}