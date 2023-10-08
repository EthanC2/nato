cmake_minimum_required(VERSION 3.26)

project(
    nato 
    VERSION 1.0.0
    DESCRIPTION "A NATO phonetic alphabet translator"
    HOMEPAGE_URL "https://github.com/EthanC2/nato"
    LANGUAGES C
)

add_executable(nato src/main.c)
