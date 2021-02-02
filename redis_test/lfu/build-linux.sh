CurrentDir=$0
CurrentDir="$( cd "$( dirname $CurrentDir  )" && pwd  )"
echo "CurrentDir=$CurrentDir"


mkdir -p $CurrentDi/_build/linux
cd $CurrentDir/_build/linux
cmake ../../
make