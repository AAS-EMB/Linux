cmake_minimum_required(VERSION 2.8) 		# Проверка версии CMake.
											# Если версия установленой программы
											# старее указаной, произайдёт аварийный выход.

project(single_lists)						# Название проекта

set(SOURCE_EXE main.cpp)					# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB list.cpp)					# Тоже самое, но для библиотеки

add_library(list STATIC ${SOURCE_LIB})		# Создание статической библиотеки с именем

add_executable(main ${SOURCE_EXE})			# Создает исполняемый файл с именем main

target_link_libraries(main list)			# Линковка программы с библиотекой
