This is a small project to open and close a ardunio driven solar pannel flower

# running with arduino
Open the flower.ino file in the arduino IDE. Hit the upload button, There is some console logging you can see if you press the  Serial Monitor button.

In the flower.ino file there is some extra logging you can turn on. You will need to change FlowerDriver constructor on line 18 to fit your needs 
FlowerDriver(max_position, open_threshold)

# firstime setup for cpp code
You need gcc and cmake you will also need to run these commands

## building code
open up this directory somewhere then change directory to build
`cd build` in unix, `dir build` in windows
```
run cmake ..
make
```
This will build your `FlowerDriver` lib and `gtest`

## testing code
``` 
cd build
make && ctest --output-on-failure
```
This will run all  of the tests in the test dir and either passed or what failed and why. 