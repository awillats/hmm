@page Tutorial
@tableofcontents
<!-- Nicer notation here: -->
<!-- https://web.stanford.edu/~jurafsky/slp3/A.pdf -->
## Tutorial & Technical Overview: How to use the HMM library

### scope of this tutorial
This tutorials is intended to demonstrate the basic components of a Hidden Markov Model and how to apply them using this toolbox.

As a reminder, this HMM toolbox is intended for applications with discrete or categorical observations.

### relevant publications
[ A tutorial on hidden Markov models and selected applications in speech recognition
(1989) Rabiner ](https://ieeexplore.ieee.org/document/18626)

Tutorial-style paper for HMMs in neuroscience: [Hidden Markov models for the stimulus-response relationships of multistate neural systems (2011) Escola et al.](https://pubmed.ncbi.nlm.nih.gov/21299424/)

Efficient modifications of HMM decoding: [Short-time Viterbi for online HMM decoding (2008) Bloit & Rodet](https://ieeexplore.ieee.org/document/4518061)

### building a model
<!-- add diagram here -->

for this tutorial we will call the latent, discrete-valued state \f$q_t\f$ and the observed discrete-valued emission signal \f$s_t\f$. In our applications \f$s_t\f$ is often a vector of binary spike counts.

state transition probability:

\f[
\left[ q_{t+1} \right] = \left[ \alpha \right] \left[ q_t \right]
\f]
spike emission probability:
\f[
s_{t} = Bernoulli( \eta(q_t) )
\f]
(note, while a Bernoulli emission process is shown here, this toolbox works with any probability mass function)

**The parameters of the spiking Hidden Markov Model (HMM)** which get estimated in the training phase are the transition probabilities between states
\f[p(q_{k+1} = i | q_{k} = j)  = a_{ij}\f]

the spiking probabilities for each of the states
\f[p(s_k = 1 | q_k = i)  = \eta_i\f]

 and the initial distribution over hidden states
 \f[ p(q_{0} = i) = \pi_i \f]

We'll call this collection of paramters
\f[ \Theta_{HMM} = \{\pi, a, \eta\} \f]


**fitting parameters**

Estimating the parameters requires a guess for the state sequence and estimating the state sequence requires a guess for the parameters. This problem is solved by an establish alternating estimation scheme known generally as expectation-maximization, or Baum-Welch specifically for Hidden Markov Models.

Currently parameter fitting is accomplished through MATLAB:
```MATLAB
[TR_estimated, EM_estimated] = hmmtrain(emission_sequence, TR_guess, EM_guess)
```
These parameters can then be loaded into the [`rtxi-hmmDecoder`](https://github.com/stanley-rozell/rtxi-hmmDecoder) or [`rtxi-hmmGenerator`](https://github.com/stanley-rozell/rtxi-hmmGenerator) modules as vectors of vectors in C++

```cpp
std::vector<std::vector<double>> trs = {{0.9,0.1},{.1,.9}}; //transition probabilities, alpha
std::vector<std::vector<double>> frs = {{0.9,0.1},{.2,.8}}; //emission probabilities, eta
std::vector<double> pis = {.1, .9}; //initial state probabilites, pi

int nStates = 2;
int nEmission = 2;

//build the model as an instance of the HMMv class
HMMv myHMM = HMMv(nStates, nEmission, trs, frs, pis);

//log the parameters to the console
myHMM.printMyParams();
```

### generating sequences

In order to simulate the Hidden Markov Model it is useful to generate a sequence of states (\f$q\f$) and observations (\f$s\f$) from a set of parameters (\f$\Theta_{HMM} = \{\pi, a, \eta\}\f$).

```cpp
nt = 1000; //number of samples to generate
printMode = 1; //print outputs as blocks

myHMM.genSeq(nt);
// sequence is stored internally
// as this.spikes and this.states

myHMM.printSeqs(printMode);
//print spikes and states to console
```
(note genSeq is mostly useful in debugging, but is unlikely to be required in a final application of the decoder)


### decoding states - overview of Viterbi algorithm

The other subtask for training the HMM is to estimate the sequence of state transitions given a guess for the parameters.
\f$p(q | s, \Theta_{HMM} = \{\pi, a, \eta\})\f$

After the training phase, the parameters of the model are held fixed and states are estimated using the Viterbi algorithm, with a modification to discard old spiking dating which is no longer informative about the current state [ [REF BLOIT] ](Bloit2008.com)

```cpp
//printMode = 1; //print outputs as blocks

int* vguess = viterbi(myHMM, myHMM.spikes, nt);
//decodes states

myHMM.printSeqs(printMode);
// print true state and spikes to console
printVecAsBlock(&vguess[0], myHMM.ntPrint, printMode);
//prints guessed state vector to the console

```
<img src="./imgs/2state_console.png" alt="2 state results" width="700"/>

### examining outputs

A key metric for evaluting the performance of HMM decoding is the accuracy which can be calculated simply as
\f[\textrm{accuracy} = \frac{\# \textrm{correctly classified samples}}{ \textrm{total num. of samples}} \f]
