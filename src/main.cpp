#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <noisekernel/Signal.h>
#include <noisekernel/Exception.h>
#include "Logger.h"
#include "NoiseRandomizer.h"
#include "Arguments.h"
#include "Simple555Pattern.h"
#include "RandomPattern.h"
#include "GPIOApplier.h"
#include "GPIOObject.h"

using namespace std;

int main(int argc, char* argv[])
{
    try
    {   
        srand(time(NULL));
        
        // Parse Arguments
        NoiseKernel::ArgumentProvider provider(argc, argv);
        Arguments arguments(&provider);
        arguments.registerArguments();

        if (provider.hasArg("help"))
        {
            cout << arguments.help() << endl;
            exit(0);
        }

        cout << "noiserandomizer" << endl << endl;

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
        Simple555Pattern *simple555Pattern2 = new Simple555Pattern(500, 1500);
        Simple555Pattern *simple555Pattern3 = new Simple555Pattern(250, 1750);
        RandomPattern *randomPattern1 = new RandomPattern(false, 500, 1000, 250, 1390);
        RandomPattern *randomPattern2 = new RandomPattern(true, 1000, 2000, 500, 3000);

        // Build GPIO Pins
        GPIOOutObject gpioOut4("4");
        gpioOut4.setup(); 

        // Build Randomizer
        vector<Pattern*> patterns;
        patterns.push_back(simple555Pattern);
        patterns.push_back(simple555Pattern2);
        patterns.push_back(simple555Pattern3);
        patterns.push_back(randomPattern1);
        patterns.push_back(randomPattern2);

        StateApplier* applier = (StateApplier*) new GPIOApplier(&gpioOut4);

        NoiseRandomizerConfig config;
        config.useRandomPattern = arguments.useRandomPatterns();
        config.changePatternMsFreq = 1000 * arguments.patternChangeMsFreq();
        
        NoiseRandomizer randomizer(&logger, &signalAdapter, patterns, applier, config);

        // Run
        randomizer.run();

        // Finalize
        delete applier;
        delete simple555Pattern3;
        delete simple555Pattern2;
        delete simple555Pattern;
        delete randomPattern1;
        delete randomPattern2;
    }
    catch (NoiseKernel::DomainException &e)
    {
        cerr << handle(e) << endl;
        exit(1);
    }
    catch (NoiseKernel::RuntimeException &e)
    {
        cerr << handle(e) << endl;
        exit(1);
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
        exit(1);
    }

    cout << "Bye Bye.." << endl;
}
