//
//  CmdLineParser.cpp
//  CmdLineParser
//
//  Created by Swasti Gupta on 5/31/15.
//
//
#include "CmdLineParser.h"

/*
 Param starting index of command line
 Param end index of command line
 Param command line parameter 
 Description returns the value followed by specified 
             command line parameter otherwise NULL
*/
char* CmdLineParser::getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return NULL;
}

/*
 Param starting index of command line
 Param end index of command line
 Param command line parameter 
 Description returns wheather a parameter is present in command Line or not
*/
bool CmdLineParser:: cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}