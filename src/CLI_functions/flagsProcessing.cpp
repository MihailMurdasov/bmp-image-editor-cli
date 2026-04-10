#include "flagsProcessing.hpp"

struct option 
long_options[] = {
    {"input", required_argument, nullptr, 'i'},
    {"output", required_argument, nullptr, 'o'},
    {"squared_lines", no_argument, nullptr, 0},
    {"left_up", required_argument, nullptr, 0},
    {"side_size", required_argument, nullptr, 0},
    {"thickness", required_argument, nullptr, 0},
    {"color", required_argument, nullptr, 0},
    {"fill", no_argument, nullptr, 0},
    {"fill_color", required_argument, nullptr, 0},
    {"rgbfilter", no_argument, nullptr, 0},
    {"component_name", required_argument, nullptr, 0},
    {"component_value", required_argument, nullptr, 0},
    {"rotate", no_argument, nullptr, 0},
    {"right_down", required_argument, nullptr, 0},
    {"angle", required_argument, nullptr, 0},
    {"circle", no_argument, nullptr, 0},
    {"center", required_argument, nullptr, 0},
    {"num", required_argument, nullptr, 0},
    {"radius", required_argument, nullptr, 0},
    {"info", no_argument, nullptr, 0},
    {"help", no_argument, nullptr, 'h'},

    {"outside_ornament", no_argument, nullptr, 0},

    {0, 0, 0, 0},
};


std::unordered_map<std::string, std::string> 
getArgs(int argc, char** argv) {

    std::unordered_map<std::string, std::string> argsMap;
    std::string option_name;
    int option = 0;
    opterr = 0;
    int ind = 0;
    
    argsMap["output"] = "out.bmp";

    bool user_output = false;

    while ((option = getopt_long(argc, argv, "i:o:h", long_options, &ind)) != -1) {

        if (option == '?') {
            std::cerr << "cw: Нераспознанный параметр «" << argv[optind - 1] << "»" << std::endl;
            useHelp();
            exit(43);
        }

        if (option == 'i') {
            option_name = "input";
        } else if (option == 'o') {
            user_output = true;
            argsMap.erase("output");
            option_name = "output";
        } else if (option == 'h') {
            printHelp();
            exit(0);
        } else {
            option_name = long_options[ind].name;
        }

        if (optarg) {
            argsMap.insert(std::make_pair(option_name, optarg));
        } else {
            argsMap.insert(std::make_pair(option_name, ""));
        }

    }

    if (argsMap.find("input") == argsMap.end()) {
        if (optind < argc) {
            argsMap.insert(std::make_pair("input", argv[argc - 1]));
            optind++;
        } else {
            std::cerr << "cw: Не указан входной файл." << std::endl;
            useHelp();
            exit(40);
        }
    }

    if (optind < argc) {
        std::cerr << "cw: Неизвестные аргументы: ";
        for (int i = optind; i < argc; i++) {
            std::cerr << argv[i] << ", ";
        }
        std::cerr << "\b\b \b\b" << std::endl;
        useHelp();
        exit(44);
    }
    
    if (getFuncName(argsMap) == "--info" && user_output == false) {
        argsMap.erase("output");
    }

    if (argsMap.find("output") != argsMap.end() && argsMap["input"] == argsMap["output"]) {
        std::cerr << "cw: Входной и выходной файлы должны иметь разные имена." << std::endl;
        useHelp();
        exit(44);
    }

    return argsMap;

}

void 
isCorrectFlags(std::vector<std::string> flags, std::unordered_map<std::string, std::string> argsMap) {

    std::vector<std::string> extraFlags;
    std::vector<std::string> missingFlags;

    bool correct = true;

    for (const auto& key : flags) {
        if (argsMap.find(key) == argsMap.end()) {
            if (key != "fill" && key != "fill_color"){
                correct = false;
                missingFlags.push_back(key);
            }
        }
    }

    if (argsMap.find("fill") == argsMap.end() && argsMap.find("fill_color") != argsMap.end() &&
        find(flags.begin(), flags.end(), "fill") != flags.end() && find(flags.begin(), flags.end(), "fill_color") != flags.end()) {
        //correct = false;
        //missingFlags.push_back("fill");
        std::cerr << "cw: Вы не используете <--fill>. Параметр <--fill_color> будет проигнорирован." << std::endl;
    } else if (argsMap.find("fill") != argsMap.end() && argsMap.find("fill_color") == argsMap.end() &&
        find(flags.begin(), flags.end(), "fill") != flags.end() && find(flags.begin(), flags.end(), "fill_color") != flags.end()) {
        correct = false;
        missingFlags.push_back("fill_color");
    }

    for (const auto& [key, value] : argsMap) {
        if (find(flags.begin(), flags.end(), key) == flags.end()) {
            correct = false;
            extraFlags.push_back(key);
        }
    }

    if (correct == false) {

        if (extraFlags.empty() == false) {
            for (const auto& item: extraFlags) {
                std::cerr << "cw: Параметр <--" << item << "> не используется выбранной опцией." << std::endl;
            }
        }

        if (missingFlags.empty() == false) {
            std::cout << "cw: Пропущены обязательные параметры: ";
            for (const auto& item : missingFlags) {
                std::cout << "<--" << item << "> ";
            }
            std::cout << std::endl;

        }

        useHelp();
        exit(43);
    }

}

std::string
getFuncName(std::unordered_map<std::string, std::string> argsMap) {
    std::string funcName;
    int cnt = 0;
    for (const auto& [key, val] : argsMap) {
        if (key == "squared_lines") {
            funcName = key; 
            cnt++;
        } else if (key == "rgbfilter") {
            funcName = key; 
            cnt++;
        } else if (key == "rotate") {
            funcName = key;
            cnt++;
        } else if (key == "circle") {
            funcName = key;
            cnt++;
        } else if (key == "info") {
            funcName = key;
            cnt++;
        } else if (key == "outside_ornament") {
            funcName = key;
            cnt++;
        }
    }

    if (cnt == 0) {
        std::cerr << "cw: Не указана операция для выполнения." << std::endl;
        useHelp();
        exit(43);
    } else if (cnt > 1) {
        std::cerr << "cw: Используйте одну операцию." << std::endl;
        useHelp();
        exit(43);
    } else if (cnt == 1) {
        return "--" + funcName;
    }

}