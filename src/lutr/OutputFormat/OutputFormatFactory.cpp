/*
 *  OutputFormatFactory.cpp
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 */

#include <string>

#include "OutputFormatFactory.h"
#include "ConsoleOutputFormat.h"
#include "CubeOutputFormat.h"

const std::string OutputFormatFactory::CommandLineFlag = "--output";

/*
 *  GetOutputFormat
 *  @description: Constructs an output format object for the given format 
 *    string.
 *  @param format: A string describing the desired output format.
 *  @returns: A pointer to the newly created output format object.
 */
IOutputFormatPtr OutputFormatFactory::GetOutputFormat(std::string format) {
    // If the flag was specified but not the format, complain.
    if (format.length() < OutputFormatFactory::CommandLineFlag.length() + 1) {
        // Show usage
        return nullptr;
    }
    if (format.substr(0,OutputFormatFactory::CommandLineFlag.length() + 1) != OutputFormatFactory::CommandLineFlag + "=") {
        // Show usage
        return nullptr;
    }
    
    // Get the desired format.
    std::string desiredFormat = format.substr(OutputFormatFactory::CommandLineFlag.length() + 1, format.length() -1);
    
    if (desiredFormat == "console") {
        ConsoleOutputFormat* f = new ConsoleOutputFormat();
        
        return f;
    }
    else if (desiredFormat == "cube" || desiredFormat == "default") {
        CubeOutputFormat* f = new CubeOutputFormat();
        
        return f;
    }
    else {
        std::cout << "Unknown output format: " << desiredFormat << std::endl;
        return nullptr;
    }
}