#include <sstream>
#include <iostream>
#include "Grid.h"
#include "Robot.h"
#include "LineToCommand.h"
#include "MoveToCommand.h"
#include "DimensionCommand.h"

int main()
{
	std::string inputLine;
    std::vector<std::unique_ptr<Command>> commands;
    bool dimensionSet = false;
    int dimension = 0;

	while (inputLine != "END")
	{
        std::getline(std::cin, inputLine);
        if (inputLine == "END") break;  // Enter "END" to finish
		
		std::stringstream ss(inputLine);
        std::string command;
		ss >> command;

        if (command == "DIMENSION") 
        {
            if (dimensionSet) 
            {
                std::cerr << "Error: DIMENSION command specified multiple times.\n";
                return 1;
            }
            if (!(ss >> dimension) || dimension <= 0) 
            {
                std::cerr << "Error: Invalid dimension size.\n";
                return 1;
            }
            if (!ss.eof()) 
            {
                std::cerr << "Error: Invalid DIMENSION command format.\n";
                return 1;
            }
            dimensionSet = true;
            commands.push_back(std::make_unique<DimensionCommand>(dimension));
        }
        else if (command == "MOVE_TO") 
        {
            int x, y;
            if (!(ss >> x >> y) || !ss.eof()) 
            {
                std::cerr << "Error: Invalid MOVE_TO command format.\n";
                return 1;
            }

            commands.push_back(std::make_unique<MoveToCommand>(x, y));
        }
        else if (command == "LINE_TO") 
        {
            int x, y;
            if (!(ss >> x >> y) || !ss.eof()) 
            {
                std::cerr << "Error: Invalid LINE_TO command format.\n";
                return 1;
            }

            commands.push_back(std::make_unique<LineToCommand>(x, y));
        }
        else 
        {
            std::cerr << "Error: Unknown command '" << command << "'.\n";
            return 1;
        }
    }

    if (!dimensionSet) 
    {
        std::cerr << "Error: DIMENSION command not specified.\n";
        return 1;
    }

    Grid grid(dimension);
    Robot robot(grid);

    for (auto& command : commands) {
        command->Execute(robot);
    }

    grid.Display();
}