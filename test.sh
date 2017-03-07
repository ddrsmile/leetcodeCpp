#!/bin/bash
opt=$1
echo START TEH TESTS

problems=()
cnt=0
if [ "$opt" = "all" ] || [ -z "$opt" ]; then
  for f in $SRC_DIR/main/*.cpp
  do
    ff=${f##*/}
    ff=${ff%.*}
    problems+=("$ff")
  done
else
  problems=($opt)
fi

cnt=0
for problem in ${problems[@]}
do
  echo Run Problem $problem
  cp -f $SRC_DIR/main/$problem.cpp $SRC_DIR/main.cpp
  cp -f $SRC_DIR/sols/$problem.cpp $SRC_DIR/sols.cpp
  clang++ -std=c++11 -I $SRC_DIR $SRC_DIR/main.cpp -o $BIN_DIR/main.o
  echo "========== RESULT =========="
  $BIN_DIR/main.o $ROOT_DIR/input/$problem.txt
  echo 
  echo "=========== DONE ==========="
  let cnt=cnt+1
done
echo $cnt problems were run.
