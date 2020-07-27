set(CMAKE_C_COMPILER clang-8)
set(CMAKE_C_EMIT_LLVM_FLAGS -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone)
set(CMAKE_C_LLVM_DIS llvm-dis-8)

list(APPEND TEST_C "")

list(APPEND TEST_C "example_code_test")
list(APPEND TEST_C "simple_attr")


foreach(F ${TEST_C})
    add_custom_command(
        OUTPUT "${F}.bc"
        COMMAND ${CMAKE_C_COMPILER} ${CMAKE_C_EMIT_LLVM_FLAGS} ${CMAKE_CURRENT_LIST_DIR}/${F}.c         
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/${F}.c
        COMMENT "Compiling ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_LIST_DIR}/${F}.c to bytecode"
    )

  add_custom_target(${F} ALL DEPENDS ${F}.bc) 
    install(
        FILES ${PROJECT_BINARY_DIR}/test/${F}.bc
        DESTINATION test
    )      
endforeach()