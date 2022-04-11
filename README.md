@mainpage
@tableofcontents
# Overview: HMM - Hidden Markov Models
`hmm` is a simple set of hidden Markov model (HMM) [code](https://github.com/stanley-rozell/hmm) intended to support control of switching linear dynamical systems.

It contains methods for generating and decoding systems with discrete latent states and discrete observed signals.
![](https://github.com/stanley-rozell/hmm/blob/master/docs/imgs/hmmlogo_center_white.png)
<!-- https://github.com/stanley-rozell/hmm/blob/master/docs/imgs/hmmlogo.png -->
## Applications

see also: [`rtxi-hmmDecoder`](https://github.com/stanley-rozell/rtxi-hmmDecoder) and [`rtxi-hmmGenerator`](https://github.com/stanley-rozell/rtxi-hmmGenerator) for application of this library in modules intended for the RTXI platform


## Repository Organization
- `src` source files (*.cpp)
- `include` header files (*.h)
- `examples` demonstrating functionality, includes tutorial
- `matlab` for comparing matlab and C++ implementations
- `scripts` utilities for setting up `hmm` library
- `docs` files for creating Doxygen documentation
- `legacy` old implementations (could likely be safely deleted)

## Dependencies
- none

## Compilation & Installation

For basic project build & install
```shell
cd /path/to/repository
mkdir build && cd build
cmake .. #configure build
cmake --build . #build the project
cmake --install . #[optional] installs to default location (OS-specific),
#use `--prefix` to install to a different directory
```
<!-- make #build the project sudo make install #[optional] installs to default location (OS-specific) -->

see the build and test process in action:
<img src="./imgs/HMM_install_example_video.gif" alt="build and test" width="700"/>

For basic benchmarking and verification of a successful install
```shell
ctest -N #list tests to be performed
ctest -VV #execute tests
```

<img src="./imgs/2state_console.png" alt="2 state results" width="700"/>


## Tutorial: Understanding the HMM toolbox
- [see tutorial page here](@ref Tutorial)


## Common issues
sometimes, the first time I build after a clean install I get:
`the C compiler
    "/opt/anaconda3/bin/x86_64-apple-darwin13.4.0-clang"
  is not able to compile a simple test program.`  
This happens when i'm in a conda environment with an older version of clang
`conda deactive` usually fixes the issue

##  GitHub Page
  - [see code here](https://github.com/stanley-rozell/hmm)
<!--
```error: non-aggregate type 'std::vector<std::vector<double> >' cannot be initialized with an initializer list```

compile `main.cpp` with
```shell
clang++ -std=c++0x -o out main.cpp
```
instead

```  Cannot specify include directories for target "hmmtest" which is not built```
{CMAKE_PROJECT_NAME} needs to be the same as the over-arching folder name
# Acknowledgements -->
