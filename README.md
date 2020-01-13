## Dependencies:
+ googletest library (custom installation or from sources)
+ clang++-6.0 - for compilation
+ llvm-6.0-tools - for coverage computing

### Installation (except gtest)
    $ apt install llvm-6.0 llvm-6.0-tools llvm-6.0-dev


### Build game runfile
    $ make game_runfile.run

### Play game
    $ make game

### Run tests
    $ make tests

### Compute coverage report
    $ make coverage

### Full coverage report
    $ make coverage_full
    
### Apply coding style
    $ make pretty