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
};

#endif // Arguments_h__
