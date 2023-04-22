cmake_minimum_required(VERSION 3.25)
project(Phone_Book C)

set(CMAKE_C_STANDARD 11)

add_executable(Phone_Book main.c Linked_list.c Linked_list.h Linked_List_config.h Phone_Book.h Phone_Book.c)
