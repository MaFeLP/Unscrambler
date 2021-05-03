cmake_minimum_required(VERSION 3.17)

set(CMAKE_C_COMPILER "C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\g++.exe")
set(CMAKE_EXE_LINKER_FLAGS "-static")

project(Unscrambler)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Unscrambler
        Main.cpp
        Main.h
        Colors.h
        Runner.cpp
        Runner.h
        SpellChecker.cpp
        SpellChecker.h
        Combinations.cpp
        Combinations.h
        github/progress_bar.cpp
        github/progress_bar.hpp
        github/threads/mingw.condition_variable.h
        github/threads/mingw.shared_mutex.h
        github/threads/mingw.mutex.h
        github/threads/mingw.invoke.h
        github/threads/mingw.future.h
        github/threads/mingw.thread.h
        )

target_link_libraries(Unscrambler pthread)
