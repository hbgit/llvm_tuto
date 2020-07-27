# Update Variable PASS

This LLVM pass example aims to create a call function for each BinaryOperator instruction in the main function.


- Example:

int main()
{
    int a,b;

    a = a + b;

    b = a + a;

    return 0;
}

---------------------------
OUT:
int main()
{
    int a,b;

    a = a + b;
    __TRACK();

    b = a + a;
    __TRACK();

    return 0;
}

- RUN: 

$ opt-8 -load ./lib/libAddCallInst_pass.so -opAddFunctPass test/var_not_init.bc > var_not_init_new.bc


- OUTPUT: 

$ llvm-dis-8 test/var_not_init.bc -o test/var_not_init.ll 

$ llvm-dis-8 var_not_init_new.bc

$ sdiff test/var_not_init.ll var_not_init_new.ll 
