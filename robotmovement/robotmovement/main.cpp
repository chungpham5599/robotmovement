// robotmovement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <sstream>
#include <iostream>

int main()
{
	std::string inputLine;
    bool dimensionSet = false;
    int dimension = 0;

	while (inputLine != "END")
	{
        std::getline(std::cin, inputLine);
        if (inputLine == "END") break;  // End input with "END"
		
        std::string command;

		std::stringstream ss(inputLine);
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
