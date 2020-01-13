
CXX=clang++

CXXFLAGS=-Wall -Werror -Wextra -Ofast -march=native -std=c++17
TESTFLAGS=-g -fprofile-instr-generate -fcoverage-mapping
TESTLIBS=-lgtest -lgtest_main -lpthread
TEST_FILES=tests/dictionary_tests.cpp tests/hidden_word_tests.cpp tests/interface_tests.cpp
SRC_FILES=src/Dictionary.cpp src/HiddenWord.cpp src/Interface.cpp
SRC_HEADERS=src/Dictionary.h src/HiddenWord.h src/Interface.h


MAIN=src/main.cpp

test_runfile.run: $(TEST_FILES) $(SRC_FILES) $(SRC_HEADERS)
	$(CXX) $(CXXFLAGS)  $(SRC_FILES) $(TEST_FILES) $(TESTFLAGS) $(TESTLIBS) -I tests -o test_runfile.run

game_runfile.run: $(SRC_FILES) $(SRC_HEADERS) $(MAIN)
	$(CXX) $(CXXFLAGS)  $(MAIN) $(SRC_FILES) -o game_runfile.run

tests: test_runfile.run
	./test_runfile.run

coverage: test_runfile.run
	LLVM_PROFILE_FILE="test.profraw" ./test_runfile.run
	llvm-profdata-6.0 merge -sparse test.profraw -o test.profdata
	llvm-cov-6.0 report ./test_runfile.run -instr-profile=test.profdata

coverage_full: test_runfile.run
	LLVM_PROFILE_FILE="test.profraw" ./test_runfile.run
	llvm-profdata-6.0 merge -sparse test.profraw -o test.profdata
	llvm-cov-6.0 show ./test_runfile.run -instr-profile=test.profdata

game: game_runfile.run
	./game_runfile.run

clean:
	rm *.run
	rm *.profdata
	rm *.profraw

pretty:
	clang-format-6.0 -i -style Google **/*.cpp **/*.h
