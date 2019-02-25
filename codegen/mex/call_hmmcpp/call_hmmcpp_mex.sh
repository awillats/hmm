MATLAB="/Applications/MATLAB_R2018b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/adam/Library/Application Support/MathWorks/MATLAB/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for call_hmmcpp" > call_hmmcpp_mex.mki
echo "CC=$CC" >> call_hmmcpp_mex.mki
echo "CFLAGS=$CFLAGS" >> call_hmmcpp_mex.mki
echo "CLIBS=$CLIBS" >> call_hmmcpp_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> call_hmmcpp_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> call_hmmcpp_mex.mki
echo "CXX=$CXX" >> call_hmmcpp_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> call_hmmcpp_mex.mki
echo "CXXLIBS=$CXXLIBS" >> call_hmmcpp_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> call_hmmcpp_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> call_hmmcpp_mex.mki
echo "LDFLAGS=$LDFLAGS" >> call_hmmcpp_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> call_hmmcpp_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> call_hmmcpp_mex.mki
echo "Arch=$Arch" >> call_hmmcpp_mex.mki
echo "LD=$LDXX" >> call_hmmcpp_mex.mki
echo OMPFLAGS= >> call_hmmcpp_mex.mki
echo OMPLINKFLAGS= >> call_hmmcpp_mex.mki
echo "EMC_COMPILER=clang" >> call_hmmcpp_mex.mki
echo "EMC_CONFIG=optim" >> call_hmmcpp_mex.mki
"/Applications/MATLAB_R2018b.app/bin/maci64/gmake" -j 1 -B -f call_hmmcpp_mex.mk
