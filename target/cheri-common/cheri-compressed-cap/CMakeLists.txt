if(APPLE AND NOT (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang"))
    include_directories(SYSTEM /Library/Developer/CommandLineTools/usr/include/c++/v1)
set(CMAKE_REQUIRED_LIBRARIES -fsanitize=fuzzer)
