#include "Arguments.h"

const string Arguments::LOGLEVEL = "loglevel";
const string Arguments::LOGFILE = "logfile";

Arguments::Arguments(
    ArgumentProvider* argProvider): ArgumentAdapter(argProvider)
{

}

Arguments::~Arguments()
{

}

string Arguments::title()
{
    return "NoiseStreamer args";
}

void Arguments::registerArguments()
{
    registerArg(LOGLEVEL, "The LogLevel: TRACE, DEBUG, INFO, WARN, ERROR, FATAL. Default: INFO");
    registerArg(LOGFILE, "The file that should log. Leave blank if should log on console");
}

bool Arguments::noArgs()
{
    return false;
}

LogLevel Arguments::getLogLevel()
{
    string s = getStringValue(LOGLEVEL);
    return convertLogLevelFromString(s);
}

bool Arguments::shouldLogToFile()
{
    return hasArg(LOGFILE);
}

string Arguments::logFile()
{
    bool b = hasArg(LOGFILE);
    string f = getStringValue(LOGFILE);
    if (b && f == "")
    {
        // TODO: add exception here
        // throw DomainException(ARG0001, LOGFILE);
    }
    return f;
}

