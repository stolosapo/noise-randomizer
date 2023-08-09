# noise-randomizer
Is a simple C++ library app that generates random GPIO output intervals. It is useful for controlling relays using GPIO outputs.

![Build](https://github.com/stolosapo/noise-randomizer/actions/workflows/makefile.yml/badge.svg) ![GitHub release (latest by date)](https://img.shields.io/github/v/release/stolosapo/noise-randomizer)


### Prepare compilation
```bash
./autogen.sh
```

### Installation
```bash
./configure
make
sudo make install
sudo ldconfig /usr/local/lib
```

### Uninstallation
```bash
sudo make uninstall
```

### Run
```bash
noiserandomizer
```

## Clean all untracked files
```bash
git clean -xdf
```

### Use Library
If everything installed fine then pass `-lnoiserandomizer` parameter in linker, when build your application.
Then use it in your app like in `examples/`.
