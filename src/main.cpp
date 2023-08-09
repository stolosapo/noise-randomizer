#include <iostream>
#include <noisekernel/Signal.h>
#include "Logger.h"
#include "NoiseRandomizer.h"
#include "Arguments.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "noiserandomizer" << endl << endl;

    // Parse Arguments
    NoiseKernel::ArgumentProvider provider(argc, argv);
    Arguments arguments(&provider);

    // Setup Signals
    NoiseKernel::SignalAdapter signalAdapter;
    signalAdapter.registerSignals();
    signalAdapter.setup();

    // Setup Logger
    NoiseKernel::LogService logger = buildLogService();
    logLevel = arguments.getLogLevel();
    shouldLogOnFile = arguments.shouldLogToFile();
    logFile = arguments.logFile();
    logger.info("LogLevel set to: " + convertLogLevelToString(logLevel));

    // Build Randomizer
    vector<Pattern*> patterns;
    NoiseRandomizer randomizer(&logger, &signalAdapter, patterns);

    // Run
    randomizer.run();

    cout << "Bye Bye.." << endl;
}
