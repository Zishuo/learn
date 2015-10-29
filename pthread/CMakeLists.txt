include_directories(./)
add_executable(pthread_detached ./pthread_detached.cpp)
add_executable(pthread_once ./pthread_once.cpp)
add_executable(BlockingQueue ./test_queue.cpp)


target_link_libraries(pthread_detached pthread)
target_link_libraries(pthread_once pthread)
target_link_libraries(BlockingQueue pthread)

