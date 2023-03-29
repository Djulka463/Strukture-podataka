#!/bin/bash

dir="tests/"
num_of_tests=$(ls ./tests | wc -l)
for (( i = 1; i <= $num_of_tests; i++ )); do
  filename="Test$i.cpp"
  if [ -f "$dir$filename" ]; then
    echo "Compiling $filename..."
    g++ -std=c++11 "$dir$filename" ./LongNumber.cpp -o "${filename%.cpp}"
    if [ $? -eq 0 ]; then
      echo "Running $filename..."
      "./${filename%.cpp}"
      rm ${filename%.cpp}
    else
      echo -e "\033[5;31mTest is unsucessfull. Be sure that you implemented all methods required in test!\033[0m"
      echo -e "\033[5;31mFollow \"Undefined symbol\" error message. That means that you are missing implementation of that method that is specified!\033[0m"
      exit 1
    fi
    else
        echo "Test file $filename not found."
    fi
done
