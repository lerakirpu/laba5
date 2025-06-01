cmake_minimum_required(VERSION 3.10)

# Укажите имя проекта
project(laba5)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Укажите папки с исходными файлами
include_directories(task1 task2 task3)

# Создайте исполняемый файл для каждой задачи
add_executable(MyExecutable_task1 task1/main1.cpp task1/func1.cpp)
add_executable(MyExecutable_task2 task2/main2.cpp task2/func2.cpp)
add_executable(MyExecutable_task3 task3/main3.cpp task3/func3.cpp)
