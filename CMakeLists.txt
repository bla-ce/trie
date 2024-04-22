cmake_minimum_required (VERSION 3.27)
project (trie LANGUAGES CXX)

set(SOURCES src/main.cpp)

add_executable(trie ${SOURCES})
target_include_directories(trie PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_compile_features(trie PRIVATE cxx_std_17)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
target_compile_options(trie INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused; -pedantic; -Werrors; -Wconversion>"
)
