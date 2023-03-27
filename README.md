This is a small project to open and close a ardunio driven solar pannel flower

# firstime setup
You need gcc and cmake you will also need to run these commands
git clone https://github.com/google/googletest


# building code
open up this directory somewhere then change directory to build
`cd build` in unix, `dir build` in windows
```
run cmake ..
make
```
This will build your `FlowerDriver` lib and `gtest`

# testing code
``` 
cd build
make && ctest --output-on-failure
```
This will run all  of the tests in the test dir and either passed or what failed and why. 