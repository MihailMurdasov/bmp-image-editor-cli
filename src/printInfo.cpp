#include "printInfo.hpp"

void
printInfo(BMPImage& image) {
    
    std::cout << "___BMP_File_Header_Info___" << std::endl;
    std::cout << "signature:\t" << std::dec << image.fileHeader.bfSignature << " (" << std::hex << image.fileHeader.bfSignature << ")" << std::endl;
    std::cout << "filesize:\t" << std::dec << image.fileHeader.bfFileSize << " (" << std::hex << image.fileHeader.bfFileSize << ")" << std::endl;
    std::cout << "reserved1:\t" << std::dec << image.fileHeader.bfReserved1 << " (" << std::hex << image.fileHeader.bfReserved1 << ")" << std::endl;
    std::cout << "reserved2:\t" << std::dec << image.fileHeader.bfReserved2 << " (" << std::hex << image.fileHeader.bfReserved2 << ")" << std::endl;
    std::cout << "pixelArrOffset:\t" << std::dec << image.fileHeader.bfFileOffsetToPixelArray << "(" << std::hex << image.fileHeader.bfFileOffsetToPixelArray << ")" << std::endl;

    std::cout << "\n___BMP_Info_Header_Info___" << std::endl;
    std::cout << "headerSize:\t" << std::dec << image.infoHeader.biSize << " (" << std::hex << image.infoHeader.biSize << ")" << std::endl;
    std::cout << "width:\t" << std::dec << image.infoHeader.biWidth << " (" << std::hex << image.infoHeader.biWidth << ")" << std::endl;
    std::cout << "height:\t" << std::dec << image.infoHeader.biHeight << " (" << std::hex << image.infoHeader.biHeight << ")" << std::endl;
    std::cout << "planes:\t" << std::dec << image.infoHeader.biPlanes << " (" << std::hex << image.infoHeader.biPlanes << ")" << std::endl;
    std::cout << "bitsPerPixel:\t" << std::dec << image.infoHeader.biBitPerPixel << " (" << std::hex << image.infoHeader.biBitPerPixel << ")" << std::endl;
    std::cout << "compression:\t" << std::dec << image.infoHeader.biCompression << " (" << std::hex << image.infoHeader.biCompression << ")" << std::endl;
    std::cout << "imageSize:\t" << std::dec << image.infoHeader.biImageSize << " (" << std::hex << image.infoHeader.biImageSize << ")" << std::endl;
    std::cout << "xPixelsPerMeter:\t" << std::dec << image.infoHeader.biXPixelsPerMeter << " (" << std::hex << image.infoHeader.biXPixelsPerMeter << ")" << std::endl;
    std::cout << "yPixelsPerMeter:\t" << std::dec << image.infoHeader.biYPixelsPerMeter << " (" << std::hex << image.infoHeader.biYPixelsPerMeter << ")" << std::endl;
    std::cout << "importantColorCount:\t" << std::dec << image.infoHeader.biImportantColors << " (" << std::hex << image.infoHeader.biImportantColors << ")" << std::endl;

}

void
printHelp() {

    std::cout << "Course work for option 5.9, created by Mikhail Murdasov.\n" << std::endl;

    std::cout << "Использование: ./cw [ОПЦИЯ]… [ПАРАМЕТРЫ]… [ВХОДНОЙ ФАЙЛ]… [ВЫХОДНОЙ ФАЙЛ]…" << std::endl;

    std::cout << "Обработка ИЗОБРАЖЕНИЙ." << std::endl;

    std::cout << "Пример: ./cw --rgbfilter --component_name red --component_value 255 --input img.bmp --output out.bmp" << std::endl;

    std::cout << "\nАргументы, обязательные для длинных параметров, обязательны и для коротких." << std::endl;
    std::cout << "Рисование квадрата с диагоналями:" << std::endl;
    std::cout << "  --squared_lines              выполнение операции" << std::endl;
    std::cout << "  --left_up=[ЧИС.ЧИС]          координаты верхнего левого угла" << std::endl;
    std::cout << "  --side_size=[ЧИС]            размер стороны" << std::endl;
    std::cout << "  --thickness=[ЧИС]            толщина линий" << std::endl;
    std::cout << "  --color=[ЧИС.ЧИС.ЧИС]        цвет линий" << std::endl;
    std::cout << "  --fill                       залить квадрат" << std::endl;
    std::cout << "  --fill_color=[ЧИС.ЧИС.ЧИС]   цвет заливки\n" << std::endl;

    std::cout << "Фильтр RGB-компонент:" << std::endl;
    std::cout << "  --rgbfilter                  выполнение операции" << std::endl;
    std::cout << "  --component_name=[ЦВЕТ]      изменяемая компонента" << std::endl;
    std::cout << "  --component_value=[ЧИС]      новое значение компоненты\n" << std::endl;

    std::cout << "Поворот изображения (части) на 90/180/270 градусов:" << std::endl;
    std::cout << "  --rotate                     выполнение операции" << std::endl;
    std::cout << "  --left_up=[ЧИС.ЧИС]          координаты верхнего левого угла области" << std::endl;
    std::cout << "  --right_down=[ЧИС.ЧИС]       координаты верхнего левого угла области" << std::endl;
    std::cout << "  --angle=[ЧИС]                угол поворота\n" << std::endl;

    std::cout << "Рисование окружности:" << std::endl;
    std::cout << "  --circle                     выполнение операции" << std::endl;
    std::cout << "  --center=[ЧИС.ЧИС]           координаты центра окружности" << std::endl;
    std::cout << "  --radius=[ЧИС]               радиус окружности" << std::endl;
    std::cout << "  --thickness=[ЧИС]            толщина линии окружности" << std::endl;
    std::cout << "  --color=[ЧИС.ЧИС.ЧИС]        цвет линии" << std::endl;
    std::cout << "  --fill                       залить окружность" << std::endl;
    std::cout << "  --fill_color=[ЧИС.ЧИС.ЧИС]   цвет заливки\n" << std::endl;

    std::cout << "Прочее:" << std::endl;
    std::cout << "  -i, --input=[ПУТЬ]           путь к входному изображению" << std::endl;
    std::cout << "  -o, --output=[ПУТЬ]          путь к выходному изображению" << std::endl;
    std::cout << "  -h, --help                   вывести подробное описание" << std::endl;
    std::cout << "  --info                       вывести подробную информацию об изображении\n" << std::endl;

    std::cout << "ФОРМАТЫ:" << std::endl;
    std::cout << "Значение координат       (--left_up/--right_down/--center): [X.Y], где X – координата по x, Y – координата по y." << std::endl;
    std::cout << "Значения имени компонент (--component_name):                [ЦВЕТ], где ЦВЕТ принимает значения \"red\"/\"green\"/\"blue\"." << std::endl;
    std::cout << "Значения компонент       (--component_value):               [ЧИС], где ЧИС - число не меньшее 0 и не большее 255." << std::endl;
    std::cout << "Значения цвета           (--color/--fill_color):            [RED.GREEN.BLUE], где RED, GREEN, BLUE - числа не меньшие 0 и не большие 255." << std::endl;
    std::cout << "Значение размера стороны (--side_size):                     [ЧИС] - где ЧИС - число, большее 0." << std::endl;
    std::cout << "Значение толщины линий   (--thickness):                     [ЧИС] - где ЧИС - число, большее 0." << std::endl;
    std::cout << "Значение угла поворота   (--angle):                         [ЧИС] - где ЧИС принимает значения 90/180/270." << std::endl;
    std::cout << "Значение радиуса         (--radius):                        [ЧИС] - где ЧИС - число, большее 0.\n" << std::endl;

    std::cout << "Коды выхода:" << std::endl;
    std::cout << " 0 - все отлично," << std::endl;
    std::cout << " 40 - ошибка чтения файла," << std::endl;
    std::cout << " 41 - ошибка записи файла," << std::endl;
    std::cout << " 42 - некорректный файл," << std::endl;
    std::cout << " 43 - некорректный параметр," << std::endl;
    std::cout << " 44 - некорректный аргумент," << std::endl;
    std::cout << " 45 - некорректное завершение работы.\n" << std::endl;

    std::cout << "ПРИМЕЧАНИЕ:" << std::endl;
    std::cout << "Утилита работает только с файлами формата BMP, БЕЗ СЖАТИЯ, имеющими 24 БИТА на цвет." << std::endl;
    std::cout << "Параметр --input НЕ является обязательным. При его отсутствии в качестве пути к входному файлу будет взят последний заданный аргумент." << std::endl;
    std::cout << "Если ВЫХОДНОЙ ФАЙЛ не указан, то результат по умолчанию сохраняется в текущую директорию с именем \"out.bmp\"." << std::endl;
    std::cout << "Началом оси координат является верхний левый угол. Ось X расположена по горизонтали и растёт вправо. Ось Y расположена по вертикали и растёт вниз." << std::endl;
    std::cout << "Параметры --fill и --fill_color НЕ являются обязательными, но НЕ могут быть использованы друг без друга." << std::endl;
    std::cout << "Все вводимые числовые значения не должны выходить из диапазона от −2 147 483 648 до 2 147 483 647." << std::endl;


}

void useHelp() {
    std::cout << "\nИспользование: ./cw [ОПЦИЯ]… [ПАРАМЕТРЫ]… [ВХОДНОЙ ФАЙЛ]… [ВЫХОДНОЙ ФАЙЛ]…\nЗапустите «./cw --help» для получения более подробного описания." << std::endl;
}
