#! /bin/bash


echo "building release-version..."
g++ -Wextra -pedantic -Werror -std=c++11 *.cpp

echo "running release-version: "
./a.out

echo "building debug-version..."
g++ -Wextra -pedantic -Werror -std=c++11 *.cpp -DCVVISUAL_DEBUG

echo "running debug-version: "
./a.out
