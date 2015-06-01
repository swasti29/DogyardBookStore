//
//  CmdLineParser.h
//  CmdLineParser
//  Description header file for Command Line Parsing Class
//  Created by Swasti Gupta on 5/31/15.
//
//

#ifndef __CmdLineParser__CmdLineParser__
#define __CmdLineParser__CmdLineParser__
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

/*
 Declaring CmdLineParse Class Components
*/
class CmdLineParser
{
public:
    char* getCmdOption(char ** begin, char ** end, const std::string & option);

	bool cmdOptionExists(char** begin, char** end, const std::string& option);
};
#endif /* defined(__CmdLineParser__CmdLineParser__) */
