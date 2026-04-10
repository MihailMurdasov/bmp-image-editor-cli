#include "wrapper.hpp"

void 
fullCheck(std::string firstFlag, std::unordered_map<std::string, std::string> argsMap) {

    std::vector<std::string> squaredFlags = {"squared_lines", "left_up", "side_size", "thickness", "color", "fill", "fill_color", "input", "output"};
    std::vector<std::string> rgbFlags     = {"rgbfilter", "component_name", "component_value", "input", "output"};
    std::vector<std::string> rotateFlags  = {"rotate", "left_up", "right_down", "angle", "input", "output"};
    std::vector<std::string> circleFlags  = {"circle", "center", "radius", "thickness", "color", "fill", "fill_color", "input", "output"};
    std::vector<std::string> outsideFlags  = {"outside_ornament", "thickness", "color", "input", "output"};
    std::vector<std::string> infoFlags    = {"info", "input"};


    if (firstFlag == "--squared_lines") {
        isCorrectFlags(squaredFlags, argsMap);
        isCorrectArgs("--squared_lines", argsMap);

    }
    
    if (firstFlag == "--rgbfilter") {
        isCorrectFlags(rgbFlags, argsMap);
        isCorrectArgs("--rgbfilter", argsMap);
    }

    if (firstFlag == "--circle") {
        isCorrectFlags(circleFlags, argsMap);
        isCorrectArgs("--circle", argsMap);
    }
    
    if (firstFlag == "--rotate") {
        isCorrectFlags(rotateFlags, argsMap);
        isCorrectArgs("--rotate", argsMap);
    }

    if (firstFlag == "--outside_ornament") {
        isCorrectFlags(outsideFlags, argsMap);
        isCorrectArgs("--outside_ornament", argsMap);
    }
    
    if (firstFlag == "--info") {
        isCorrectFlags(infoFlags, argsMap);
    }  
}

void 
launchFunc(BMPImage& image, std::string funcName, std::unordered_map<std::string, std::string> argsMap) {

    bool launch = false;

    if (funcName == "--squared_lines") {    
        std::string left_up, side_size, thickness, color, fill_color;
        RGBTriple color_push, fill_color_push;

        bool fill = false;

        for (const auto& [key, val] : argsMap) {
            if (key == "left_up") left_up = val;
            if (key == "side_size") side_size = val;
            if (key == "thickness") thickness = val;
            if (key == "color") color = val;
            if (key == "fill") fill = true;
            if (key == "fill_color") fill_color = val;
        }

        std::vector<std::string> coords = split(left_up, ".");
        int x = stoi(coords[0]);
        int y = stoi(coords[1]);

        int side_size_push = stoi(side_size);
        int thickness_push = stoi(thickness);

        std::vector<std::string> color_arr = split(color, ".");
        color_push.rgbRed = stoul(color_arr[0]);
        color_push.rgbGreen = stoul(color_arr[1]);
        color_push.rgbBlue = stoul(color_arr[2]);

        if (fill == true) {
            std::vector<std::string> fill_color_arr = split(fill_color, ".");
            fill_color_push.rgbRed = stoul(fill_color_arr[0]);
            fill_color_push.rgbGreen = stoul(fill_color_arr[1]);
            fill_color_push.rgbBlue = stoul(fill_color_arr[2]);

            draw_square(image, x, y, side_size_push, thickness_push, color_push, true, fill_color_push);
            launch = true;
        } else {
            draw_square(image, x, y, side_size_push, thickness_push, color_push, false, {0,0,0});
            launch = true;
        }

    }

    if (funcName == "--rgbfilter") {    
        std::string component_name, component_value;


        for (const auto& [key, val] : argsMap) {
            if (key == "component_name") component_name = val;
            if (key == "component_value") component_value = val;
        }

        int component_value_push = stoi(component_value);

        rgbFilter(image, component_name, component_value_push);
        launch = true;
    }

    if (funcName == "--circle") {    
        std::string center, radius, thickness, color, fill_color;
        RGBTriple color_push, fill_color_push;

        bool fill = false;

        for (const auto& [key, val] : argsMap) {
            if (key == "center") center = val;
            if (key == "radius") radius = val;
            if (key == "thickness") thickness = val;
            if (key == "color") color = val;
            if (key == "fill") fill = true;
            if (key == "fill_color") fill_color = val;
        }

        std::vector<std::string> coords = split(center, ".");
        int center_x = stoi(coords[0]);
        int center_y = stoi(coords[1]);

        int radius_push = stoi(radius);
        int thickness_push = stoi(thickness);

        std::vector<std::string> color_arr = split(color, ".");
        color_push.rgbRed = stoul(color_arr[0]);
        color_push.rgbGreen = stoul(color_arr[1]);
        color_push.rgbBlue = stoul(color_arr[2]);

        if (fill == true) {
            std::vector<std::string> fill_color_arr = split(fill_color, ".");
            fill_color_push.rgbRed = stoul(fill_color_arr[0]);
            fill_color_push.rgbGreen = stoul(fill_color_arr[1]);
            fill_color_push.rgbBlue = stoul(fill_color_arr[2]);

            drawCircle(image, center_x, center_y, radius_push, thickness_push, color_push, true, fill_color_push);
            launch = true;
        } else {
            drawCircle(image, center_x, center_y, radius_push, thickness_push, color_push, false, {0, 0, 0});
            launch = true;
        }

    }

    if (funcName == "--rotate") {    
        std::string left_up, right_down, angle;

        for (const auto& [key, val] : argsMap) {
            if (key == "left_up") left_up = val;
            if (key == "right_down") right_down = val;
            if (key == "angle") angle = val;
        }

        std::vector<std::string> coords_up = split(left_up, ".");
        int x_up = stoi(coords_up[0]);
        int y_up = stoi(coords_up[1]);

        std::vector<std::string> coords_down = split(right_down, ".");
        int x_down = stoi(coords_down[0]);
        int y_down = stoi(coords_down[1]);

        int angle_push = stoi(angle);

        rotate(image, x_up, y_up, x_down, y_down, angle_push);
        launch = true;

    }

    if (funcName == "--outside_ornament") {    
        std::string thickness, color;
        RGBTriple color_push;

        for (const auto& [key, val] : argsMap) {
            if (key == "thickness") thickness = val;
            if (key == "color") color = val;
        }

        std::vector<std::string> color_arr = split(color, ".");
        color_push.rgbRed = stoul(color_arr[0]);
        color_push.rgbGreen = stoul(color_arr[1]);
        color_push.rgbBlue = stoul(color_arr[2]);

        int thickness_push = stoi(thickness);

        outside_ornament(image, thickness_push, color_push);
        launch = true;

    }

    if (funcName == "--info") {   
        printInfo(image);
        launch = true;
    }

    if (!launch) {
        std::cerr << "cw: Несуществующая операция <" + funcName + ">." << std::endl;
        useHelp();
        exit(43);
    }
}