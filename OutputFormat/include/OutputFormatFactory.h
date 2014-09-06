/*
 *  OutputFormatFactory.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A factory class that handles the creation and configuration
 *    of output format objects.
 */

#ifndef __pal2cube__OutputFormatFactory__
#define __pal2cube__OutputFormatFactory__

#include <string>

#include "IOutputFormat.h"

class OutputFormatFactory {
public:
    static IOutputFormatPtr GetOutputFormat(std::string format);
    const static std::string CommandLineFlag;
};

#endif