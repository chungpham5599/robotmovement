#include <sstream>
#include <iostream>
#include "Grid.h"
#include "Robot.h"
#include "Command.h"

int main()
{
	std::string inputLine;
    bool dimensionSet = false;
    int dimension = 0;

	while (inputLine != "END")
	{
        std::getline(std::cin, inputLine);
        if (inputLine == "END") break;  // Enter "END" to finish
		
		std::stringstream ss(inputLine);
        std::string command;
		ss >> command;

        if (command == "DIMENSION") {
            if (dimensionSet) {
                std::cerr << "Error: DIMENSION command specified multiple times.\n";
                return 1;
            }
            if (!(ss >> dimension) || dimension <= 0) {
                std::cerr << "Error: Invalid dimension size.\n";
                return 1;
            }
            dimensionSet = true;
        }
        else if (command == "MOVE_TO") {
            int x, y;
            if (!(ss >> x >> y)) {
                std::cerr << "Error: Invalid MOVE_TO command format.\n";
                return 1;
            }
        }
        else if (command == "LINE_TO") {
            int x, y;
            if (!(ss >> x >> y)) {
                std::cerr << "Error: Invalid LINE_TO command format.\n";
                return 1;
            }
        }
        else {
            std::cerr << "Error: Unknown command '" << command << "'.\n";
            return 1;
        }
    }

    if (!dimensionSet) {
        std::cerr << "Error: DIMENSION command not specified.\n";
        return 1;
    }
}