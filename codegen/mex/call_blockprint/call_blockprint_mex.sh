MATLAB="/Applications/MATLAB_R2018b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/adam/Library/Application Support/MathWorks/MATLAB/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for call_blockprint" > call_blockprint_mex.mki
echo "CC=$CC" >> call_blockprint_mex.mki
echo "CFLAGS=$CFLAGS" >> call_blockprint_mex.mki
echo "CLIBS=$CLIBS" >> call_blockprint_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> call_blockprint_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> call_blockprint_mex.mki
echo "CXX=$CXX" >> call_blockprint_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> call_blockprint_mex.mki
echo "CXXLIBS=$CXXLIBS" >> call_blockprint_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> call_blockprint_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> call_blockprint_mex.mki
echo "LDFLAGS=$LDFLAGS" >> call_blockprint_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> call_blockprint_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> call_blockprint_mex.mki
echo "Arch=$Arch" >> call_blockprint_mex.mki
echo "LD=$LDXX" >> call_blockprint_mex.mki
echo OMPFLAGS= >> call_blockprint_mex.mki
echo OMPLINKFLAGS= >> call_blockprint_mex.mki
echo "EMC_COMPILER=clang" >> call_blockprint_mex.mki
echo "EMC_CONFIG=optim" >> call_blockprint_mex.mki
"/Applications/MATLAB_R2018b.app/bin/maci64/gmake" -j 1 -B -f call_blockprint_mex.mk
