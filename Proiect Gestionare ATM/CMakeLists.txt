cmake_minimum_required(VERSION 3.24)
project(curs6)

set(CMAKE_CXX_STANDARD 17)

add_executable(curs6 main.cpp VectorDinamic.h VectorDinamic.cpp TestVectorDinamic.h TestVectorDinamic.cpp Colectie.cpp Colectie.h ATM.cpp ATM.h Tranzaction.cpp Tranzaction.h TRepo.cpp TRepo.h BKT.h BKT.cpp)
