#ifndef Arguments_h__
#define Arguments_h__

#include <string>
#include <noisekernel/Argument.h>
#include "Logger.h"

using namespace std;
using namespace NoiseKernel;

class Arguments: public ArgumentAdapter
{
private:
    static const string LOGLEVEL;
    static const string LOGFILE;
    static const string USE_RANDOM_PATTERNS;
    static const string PATTERN_CHANGE_MS_FREQ;

protected:
    virtual string title();

public:
    Arguments(ArgumentProvider* argProvider);
    virtual ~Arguments();

    virtual void registerArguments();
    bool noArgs();

    LogLevel getLogLevel();
    bool shouldLogToFile();
    string logFile();

    bool useRandomPatterns();
    int patternChangeMsFreq();
};

#endif // Arguments_h__
