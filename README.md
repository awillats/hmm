# HMM - Hidden Markov Models
`hmm` is a simple set of hidden Markov model (HMM) code intended to support control of switching linear dynamical systems.

It contains methods for generating and decoding systems of the form:

_generative equations here - transition, emission_


# Applications

see also: [`rtxi-hmmDecoder`](google.com) and [`rtxi-hmmGenerator`](google.com) for application of this library in modules intended for the RTXI platform


# Repository Organization

# Dependencies
- eigen

# Compilation & Installation

[ In Progress ]
- For basic project build & install
	```shell
	cd /path/to/repository
	mkdir build && cd build
	cmake .. #configure build
	make #build the project
	sudo make install #[optional] installs to default location (OS-specific)
	```


# Common issues

```error: non-aggregate type 'std::vector<std::vector<double> >' cannot be initialized with an initializer list```

compile `main.cpp` with
```shell
clang++ -std=c++0x -o out main.cpp
```
instead

```  Cannot specify include directories for target "hmmtest" which is not built```
{CMAKE_PROJECT_NAME} needs to be the same as the over-arching folder name
# Acknowledgements
