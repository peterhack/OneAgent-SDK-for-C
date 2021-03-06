#
# Copyright 2017 Dynatrace LLC
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 2.8.12)

include("${CMAKE_CURRENT_LIST_DIR}/../../onesdk-config.cmake")

project(sample1)
add_executable(sample1 main.cpp)

# enable use of C++11
if (CMAKE_VERSION VERSION_LESS "3.1")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++11" ONESDK_HAVE_CXX11)
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" ONESDK_HAVE_CXX0X)
    if (ONESDK_HAVE_CXX11)
        target_compile_options(sample1 PUBLIC -std=c++11)
    elseif (ONESDK_HAVE_CXX0X)
        target_compile_options(sample1 PUBLIC -std=c++0x)
    endif ()
else ()
    set_property(TARGET sample1 PROPERTY CXX_STANDARD 11)
endif ()

# enable use of threads
find_package(Threads REQUIRED)
if (THREADS_HAVE_PTHREAD_ARG)
    target_compile_options(sample1 PUBLIC "-pthread")
endif()
if (CMAKE_THREAD_LIBS_INIT)
    target_link_libraries(sample1 "${CMAKE_THREAD_LIBS_INIT}")
endif ()

# link to SDK library
target_link_libraries(sample1 onesdk_static)
