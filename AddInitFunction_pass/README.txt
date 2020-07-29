# Update Variable PASS

This LLVM pass example aims to create a call function to initialize each variable not initialize in the main function.


- Example:

int main(){
    int k;

    int d = k;

    return d;
}

---------------------------
- OUT:
int main(){
    int k;
    
    k = __MY_INT(); // return a int

    int d = k;

    return d;
}

- RUN: 

$ opt-8 -load ./lib/libAddInitFunction_pass.so -opAddFunct2VarPass test/init_main.bc > init_main_new.bc


- OUTPUT: 

$ llvm-dis-8 test/init_main.bc -o test/init_main.ll 

$ llvm-dis-8 init_main_new.bc

$ sdiff test/init_main.ll init_main_new.ll 
