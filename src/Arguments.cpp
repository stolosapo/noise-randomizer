#include "Arguments.h"

const string Arguments::LOGLEVEL = "loglevel";
const string Arguments::LOGFILE = "logfile";
const string Arguments::USE_RANDOM_PATTERNS = "random_patterns";
const string Arguments::PATTERN_CHANGE_MS_FREQ = "pattern_change_freq";

Arguments::Arguments(
    ArgumentProvider* argProvider): ArgumentAdapter(argProvider)
{

}

Arguments::~Arguments()
{

}

string Arguments::title()
{
    return "NoiseRandomizer args";
}

void Arguments::registerArguments()
{
    registerArg(LOGLEVEL, "The LogLevel: TRACE, DEBUG, INFO, WARN, ERROR, FATAL. Default: INFO");
    registerArg(LOGFILE, "The file that should log. Leave blank if should log on console");
    registerArg(USE_RANDOM_PATTERNS, "If we want a pattern change to be random. Default false");
    registerArg(PATTERN_CHANGE_MS_FREQ, "The frequency that the pattern will change, if blank or 0 then no change will happen");
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

bool Arguments::useRandomPatterns()
{
    bool u = getBoolValue(USE_RANDOM_PATTERNS);
    return u;
}

int Arguments::patternChangeMsFreq()
{
    int f = getIntValue(PATTERN_CHANGE_MS_FREQ);
    return f;
}
