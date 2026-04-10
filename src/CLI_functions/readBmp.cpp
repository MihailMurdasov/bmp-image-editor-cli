#include "readBmp.hpp"

BMPImage 
readBmp(const std::string& filename) {
    
    std::ifstream file(filename, std::ios::binary);

    try {
        if (!file.is_open()) {
            throw std::runtime_error("cw: Невозможно открыть файл: " + filename);
        }        
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(40);
    }

    BMPImage image;
    file.read((char*)&image.fileHeader, sizeof(BMPFileHeader));

    try {
        if (image.fileHeader.bfSignature != 0x4D42) {
            throw std::runtime_error("cw: Данный файл не является файлом формата BMP.");
        }       
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(42);
    }

    file.read((char*)&image.infoHeader, sizeof(BMPInfoHeader));

    try {
        if (image.infoHeader.biBitPerPixel != 24) {
            throw std::runtime_error("cw: Данный файл не имеет 24 бита на цвет.");
        }      
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(42);
    }

    try {
        if (image.infoHeader.biCompression != 0) {
            throw std::runtime_error("cw: Данный файл использует сжатие.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(42);
    }


    file.seekg(image.fileHeader.bfFileOffsetToPixelArray, std::ios::beg);

    unsigned int padding = (image.infoHeader.biWidth * sizeof(RGBTriple)) % 4;
    if (padding) padding = 4 - padding;

    std::vector<std::vector<RGBTriple>> 
    pixels_arr(abs(image.infoHeader.biHeight), std::vector<RGBTriple>(image.infoHeader.biWidth));

    for (int i = image.infoHeader.biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < image.infoHeader.biWidth; j++) {
            RGBTriple pixel;
            file.read((char*)&pixel, sizeof(RGBTriple));
            pixels_arr[i][j] = pixel;
        }
        file.seekg(padding, std::ios::cur);
    }

    image.pixelsArr.resize(abs(image.infoHeader.biHeight), std::vector<RGBTriple>(image.infoHeader.biWidth));
    image.pixelsArr = pixels_arr;

    file.close();

    return image;
}
