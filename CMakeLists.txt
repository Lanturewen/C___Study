cmake_minimum_required(VERSION 3.23)
project(C___Study)

set(CMAKE_CXX_STANDARD 14)

#add_executable(C___Study day01_11_02/quickSort.cpp day01_11_02/cmp.cpp day01_11_02/ListNode.cpp day01_11_02/TreeNode.cpp day01_11_02/LeetCode_242.cpp day01_11_02/LeetCode_349.cpp)
# 遍历项目根目录下所有的 .cpp 文件
file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} day01_11_02/LeetCode_347.cpp)
    message (\ \ \ \ --\ ${file}\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
