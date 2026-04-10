#include "CLI_functions/wrapper.hpp"
#include "CLI_functions/readBmp.hpp"
#include "CLI_functions/writeBmp.hpp"

int
main(int argc, char** argv) {

    if (argc < 2) {
        std::cout << "cw: Пропущены аргументы." << std::endl;
        useHelp();
        return 43;
    }
    
    try {
        std::unordered_map<std::string, std::string> argsMap = getArgs(argc, argv);
        std::string funcToRun = getFuncName(argsMap);
        fullCheck(funcToRun, argsMap);
        BMPImage bmp = readBmp(argsMap["input"]);
        launchFunc(bmp, funcToRun, argsMap);
        if (argsMap.find("output") != argsMap.end()) {
            writeBmp(bmp, argsMap["output"]);
        }
    } 
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        std::cout << "cw: Некорректное завершение работы\n";
        useHelp();
        return 45;
    }
    
    return 0;
}