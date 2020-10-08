cmake_minimum_required(VERSION 2.8) 		# Проверка версии CMake.
											# Если версия установленой программы
											# старее указаной, произайдёт аварийный выход.

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

add_executable(main main.cpp)				# Создает исполняемый файл с именем main
											# из исходника main.cpp
