#include <vector>
#include <stdint.h>

#pragma once
#pragma pack(push, 1)

typedef struct BMPFileHeader {
    uint16_t bfSignature;
    uint32_t bfFileSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfFileOffsetToPixelArray;
}BMPFileHeader;

typedef struct BMPInfoHeader {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitPerPixel;
    uint32_t biCompression;
    uint32_t biImageSize;
    int32_t biXPixelsPerMeter;
    int32_t biYPixelsPerMeter;
    uint32_t biTotalColors;
    uint32_t biImportantColors;
}BMPInfoHeader;

typedef struct RGBTriple {
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;

    bool operator==(const RGBTriple& other) const {
        return rgbRed == other.rgbRed && rgbGreen == other.rgbGreen && rgbBlue == other.rgbBlue;
    }

    bool operator<(const RGBTriple& other) const {
        if (rgbRed != other.rgbRed) return rgbRed < other.rgbRed;
        if (rgbGreen != other.rgbGreen) return rgbGreen < other.rgbGreen;
        return rgbBlue < other.rgbBlue;
    }

} RGBTriple;

typedef struct coords {
    int x0;
    int x1;
    int y0;
    int y1;
}coords;

typedef struct BMPImage {
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    std::vector<std::vector<RGBTriple>> pixelsArr;
}BMPImage;

#pragma pack(pop)
