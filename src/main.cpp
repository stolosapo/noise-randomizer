#include <iostream>
#include <noisekernel/Signal.h>
#include "Logger.h"
#include "NoiseRandomizer.h"
#include "Arguments.h"
#include "Simple555Pattern.h"
#include "GPIOApplier.h"

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

    // Build Patterns
    Simple555Pattern *simple555Pattern = new Simple555Pattern(1, 1);

    // Build Randomizer
    vector<Pattern*> patterns;
    patterns.push_back(simple555Pattern);

    StateApplier* applier = (StateApplier*) new GPIOApplier;
    
    NoiseRandomizer randomizer(&logger, &signalAdapter, patterns, applier);

    // Run
    randomizer.run();

    // Finalize
    delete applier;
    delete simple555Pattern;

    cout << "Bye Bye.." << endl;
}
