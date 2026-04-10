#include "validateArgs.hpp"

void 
isCorrectArgs(std::string funcName, std::unordered_map<std::string, std::string> argsMap) {

    if (funcName == "--squared_lines") {    
        std::string left_up, side_size, thickness, color, fill_color;

        bool fill_check = false;

        for (const auto& [key, val] : argsMap) {
            if (key == "left_up") left_up = val;
            if (key == "side_size") side_size = val;
            if (key == "thickness") thickness = val;
            if (key == "color") color = val;
            if (key == "fill") fill_check = true;
            if (key == "fill_color") fill_color = val;
        }
        
        if (fill_check == false) {
            validateDrawSquare(left_up, side_size, thickness, color);
        } else {
            validateDrawSquare(left_up, side_size, thickness, color, fill_color);
        }
    }

    if (funcName == "--rgbfilter") {
        std::string component_name, component_value;

        for (const auto& [key, val] : argsMap) {
            if (key == "component_name") component_name = val;
            if (key == "component_value") component_value = val;
        }

        validateRGBfilter(component_name, component_value);
    }

    if (funcName == "--circle") {
        std::string center, radius, thickness, color, fill_color;

        bool fill_check = false;

        for (const auto& [key, val] : argsMap) {
            if (key == "center") center = val;
            if (key == "radius") radius = val;
            if (key == "thickness") thickness = val;
            if (key == "color") color = val;
            if (key == "fill") fill_check = true;
            if (key == "fill_color") fill_color = val;
        }

        if (fill_check == false) {
            validateCircle(center, radius, thickness, color);
        } else {
            validateCircle(center, radius, thickness, color, fill_color);
        }
    }

    if (funcName == "--rotate") {
        std::string left_up, right_down, angle;

        for (const auto& [key, val] : argsMap) {
            if (key == "left_up") left_up = val;
            if (key == "right_down") right_down = val;
            if (key == "angle") angle = val;
        }

        validateRotate(left_up, right_down, angle);
    }

    if (funcName == "--outside_ornament") {    
        std::string thickness, color;

        for (const auto& [key, val] : argsMap) {
            if (key == "thickness") thickness = val;
            if (key == "color") color = val;
        }

        validateOutside(thickness, color);
    }
}



std::vector<std::string> 
split(const std::string& str, const std::string& delim) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = 0;
    while ((end = str.find(delim, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delim.length();
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

void 
isValidCoords(std::string coords, std::string arg) {
    std::regex pattern_coord("^-?\\d+\\.-?\\d+$");
    try {
        if(std::regex_match(coords, pattern_coord) == false){
            throw std::runtime_error("cw: Некорректный формат параметра <" + arg + ">.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }
    std::vector<std::string> coords_val = split(coords, ".");
    try {
        int x = stoi(coords_val[0]);
        int y = stoi(coords_val[1]); 
    } catch (std::out_of_range& err) {
        std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <" + arg + ">." << std::endl;
        useHelp();
        exit(44);                
    }

}

void 
isValidColor(std::string color, std::string arg) {
    std::regex pattern_color("^\\d+\\.\\d+\\.\\d+$");
    try {
        if(std::regex_match(color, pattern_color) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <" + arg + ">.");
        } else {

            int color_r, color_g, color_b;
            std::vector<std::string> colors_arr = split(color, ".");

            try {
                color_r = stoi(colors_arr[0]);
                color_g = stoi(colors_arr[1]);
                color_b = stoi(colors_arr[2]);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <" + arg + ">." << std::endl;
                useHelp();
                exit(44);                
            }
            
            if (!(color_r >= 0 && color_r <= 255)) throw std::runtime_error("cw: Некорректное значение RED в параметре <" + arg + ">."); 
            if (!(color_g >= 0 && color_g <= 255)) throw std::runtime_error("cw: Некорректное значение GREEN в параметре <" + arg + ">.");
            if (!(color_b >= 0 && color_b <= 255)) throw std::runtime_error("cw: Некорректное значение BLUE в параметре <" + arg + ">.");

        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }
}

bool 
validateDrawSquare(std::string left_up, std::string side_size, std::string thickness, std::string color) {
 
    std::regex pattern_size("^\\d+$");
    std::regex pattern_thickness("^\\d+$");

    isValidCoords(left_up, "--left_up");

    try {
        if (std::regex_match(side_size, pattern_size) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--side_size>.");
        } else {

            int size;
            try {
                size = stoi(side_size);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--side_size>." << std::endl;
                useHelp();
                exit(44);                
            }
            if (size <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--sise_size>.");

        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }
    
    try {
        if (std::regex_match(thickness, pattern_thickness) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--thickness>.");
        } else {

            int thickness_int;
            try {
                thickness_int = stoi(thickness);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--thickness>." << std::endl;
                useHelp();
                exit(44);                
            }

            if (thickness_int <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--thickness>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

    isValidColor(color, "--color");

    return true;

}

bool 
validateDrawSquare(std::string left_up, std::string side_size, std::string thickness, std::string color, std::string fill_color) {

    std::regex pattern_size("^\\d+$");
    std::regex pattern_thickness("^\\d+$");

    isValidCoords(left_up, "--left_up");

    try {
        if (std::regex_match(side_size, pattern_size) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--side_size>.");
        } else {

            int size;
            try {
                size = stoi(side_size);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--side_size>." << std::endl;
                useHelp();
                exit(44);                
            }
            if (size <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--sise_size>.");

        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }
    
    try {
        if (std::regex_match(thickness, pattern_thickness) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--thickness>.");
        } else {

            int thickness_int;
            try {
                thickness_int = stoi(thickness);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--thickness>." << std::endl;
                useHelp();
                exit(44);                
            }

            if (thickness_int <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--thickness>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

    isValidColor(color, "--color");

    isValidColor(fill_color, "--fill_color");
    
    return true;

}


void 
validateRGBfilter(std::string component_name, std::string component_value) {

    std::regex pattern_value("^\\d+$");

    try {
        if (!(component_name == "red" || component_name == "green" || component_name == "blue")) {
            throw std::runtime_error("cw: Некорректное значение параметра <--component_name>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

    try {
        if (std::regex_match(component_value, pattern_value) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--component_value>.");
        } else {

            int value;
            try {
                value = stoi(component_value);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--component_value>." << std::endl;
                useHelp();
                exit(44);                
            }

            if (!(value >= 0 && value <= 255)) throw std::runtime_error("cw: Некорректное значение параметра <--component_value>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);

    }

}

void 
validateRotate(std::string left_up, std::string right_down, std::string angle) {

    isValidCoords(left_up, "--left_up");

    isValidCoords(right_down, "--right_down");

    try {
        if (!(angle == "90" || angle == "180" || angle == "270")) {
            throw std::runtime_error("cw: Некорректное значение параметра <--angle>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

    std::vector<std::string> coords_up = split(left_up, ".");
    int x_up = stoi(coords_up[0]);
    int y_up = stoi(coords_up[1]);

    std::vector<std::string> coords_down = split(right_down, ".");
    int x_down = stoi(coords_down[0]);
    int y_down = stoi(coords_down[1]);

    try {
        if (!(x_up <= x_down && y_up <= y_down)) { //
            throw std::runtime_error("cw: Возможно, вы перепутали <--left_up> и <--right_down>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

}

bool 
validateCircle(std::string center, std::string radius, std::string thickness, std::string color) {

    std::regex pattern_radius("^\\d+$");
    std::regex pattern_thickness("^\\d+$");

    isValidCoords(center, "--center");

    try {
        if (std::regex_match(radius, pattern_radius) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--radius>.");
        } else {

            int value;
            try {
                value = stoi(radius);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--radius>." << std::endl;
                useHelp();
                exit(44);                
            }

            if (value <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--radius>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

    try {
        if (std::regex_match(thickness, pattern_thickness) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--thickness>.");
        } else {

            int thickness_int;
            try {
                thickness_int = stoi(thickness);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--thickness>." << std::endl;
                useHelp();
                exit(44);                
            }

            if (thickness_int <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--thickness>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

    isValidColor(color, "--color");

    return true;
}

bool 
validateCircle(std::string center, std::string radius, std::string thickness, std::string color, std::string fill_color) {

    std::regex pattern_radius("^\\d+$");
    std::regex pattern_thickness("^\\d+$");

    isValidCoords(center, "--center");

    try {
        if (std::regex_match(radius, pattern_radius) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--radius>.");
        } else {

            int value;
            try {
                value = stoi(radius);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--radius>." << std::endl;
                useHelp();
                exit(44);                
            }

            if (value <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--radius>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

    try {
        if (std::regex_match(thickness, pattern_thickness) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--thickness>.");
        } else {

            int thickness_int;
            try {
                thickness_int = stoi(thickness);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--thickness>." << std::endl;
                useHelp();
                exit(44);                
            }
            
            if (thickness_int <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--thickness>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }

    isValidColor(color, "--color");

    isValidColor(fill_color, "--fill_color");

    return true;
}

void
validateOutside(std::string thickness, std::string color) {
    isValidColor(color, "--color");

    std::regex pattern_thickness("^\\d+$");


    try {
        if (std::regex_match(thickness, pattern_thickness) == false) {
            throw std::runtime_error("cw: Некорректный формат параметра <--thickness>.");
        } else {

            int thickness_int;
            try {
                thickness_int = stoi(thickness);
            }
            catch (std::out_of_range& err) {
                std::cout << "cw: Возможно, вы ввели слишком большое/маленькое значение параметра <--thickness>." << std::endl;
                useHelp();
                exit(44);                
            }
            
            if (thickness_int <= 0) throw std::runtime_error("cw: Некорректное значение параметра <--thickness>.");
        }
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        useHelp();
        exit(44);
    }
}