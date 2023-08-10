#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <noisekernel/Signal.h>
#include "Logger.h"
#include "NoiseRandomizer.h"
#include "Arguments.h"
#include "Simple555Pattern.h"
#include "GPIOApplier.h"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    
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

    // Build Patterns
    Simple555Pattern *simple555Pattern = new Simple555Pattern(1000, 1000);

    // Build Randomizer
    vector<Pattern*> patterns;
    patterns.push_back(simple555Pattern);

    StateApplier* applier = (StateApplier*) new GPIOApplier;

    NoiseRandomizerConfig config;
    // config.useRandomPattern = false;
    // config.changePatternMsFreq = 1000 * 10;
    
    NoiseRandomizer randomizer(&logger, &signalAdapter, patterns, applier, config);

    // Run
    randomizer.run();

    // Finalize
    delete applier;
    delete simple555Pattern;

    cout << "Bye Bye.." << endl;
}
