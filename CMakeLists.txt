cmake_minimum_required(VERSION 3.5)   # CMake version check
project(leetcode)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard
set(ARRAY_SRC ./Array)
set(SOURCE_FILES ${ARRAY_SRC}/Q66_Plus_One.cpp Two_Pointers/Q632_Smallest_Range.cpp "Tree/662_Maximum_Width_of_Binary_Tree .cpp" Dynamic_Programming/Q96_Unique_Binary_Search_Trees_II.cpp Sort/Q56_Merge_Intervals.cpp Greedy/Q861_Score_After_Flipping_Matrix.cpp Tree/Q814_Binary_Tree_Pruning.cpp Tree/Q449_Serialize_and_Deserialize_BST.cpp Divide_and_Conquer/Q327_Count_of_Range_Sum.cpp Binary_Search/Q436_Find_Right_Interval.cpp Sampling/Q470_Implement_Rand10_Using_Rand7.cpp Dynamic_Programming/Q823_Binary_Trees_With_Factors.cpp DFS/Q834_Sum_of_Distances_in_Tree.cpp Hash_Table/Q560_Subarray_Sum_Equals_K.cpp "Stack/Q1019_Next_Greater_Node_In_Linked_List .cpp")            # Add main.cpp file of project root directory as source file
add_executable(Q66 ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
