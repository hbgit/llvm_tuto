#define DEBUG_TYPE "opInitVarPass"

#include <llvm/Pass.h>
#include <llvm/IR/Function.h> 
#include <llvm/IR/InstIterator.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Metadata.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h> 

#include <map>
#include <string.h> 

using namespace llvm;
namespace {
  
  struct ListFunctPass : public FunctionPass {
   
    static char ID;   
    ListFunctPass() : FunctionPass(ID) {}
    
    virtual bool runOnFunction(Function &F) {
        //errs() << "Function " << F.getName() << '\n';
        // Get the function to call from our runtime library.
        /**
         * The instrumentation code pairs with a run-time library (code.c in the repository) 
         * that defines that __VERIFIER_nondet_int function:
         * #include <stdio.h>
         *  int __VERIFIER_nondet_int(void) {
         *      //do something
         *      return int;
         * }
         * 
         * */
        LLVMContext &Ctx = F.getContext();
        std::vector<Type*> paramTypes = {Type::getInt32Ty(Ctx)};
        Type *retType = Type::getVoidTy(Ctx);
        FunctionType *logFuncType = FunctionType::get(retType, paramTypes, false);
        Constant *logFunc = F.getParent()->getOrInsertFunction("__VERIFIER_nondet_int", logFuncType);
        bool codeupdate = false;
        
        
        if (F.getName() == "main") {

          // Identify all variables
          for (auto &bb : F) {
            for (auto &instruction : bb) {
             if ( AllocaInst *allocaInst = dyn_cast<AllocaInst>(&instruction) ) {                
                
                // check variables not initialized
                // From Value LLVM
                if (allocaInst->use_empty()){
                  errs() << *allocaInst << " use_empty \n";
                  /*// Insert *after* 
                  IRBuilder<> builder(allocaInst);
                  builder.SetInsertPoint(&bb, ++builder.GetInsertPoint());

                  // Insert a call to our function. 
                  Value *v = builder.CreateGlobalStringPtr("tmp");                 
                  Value* args[] = {v};
                  builder.CreateCall(logFunc, args);
                  codeupdate = true;*/

                }else{
                  // Getting the first Use from instruction
                  Value::use_iterator use = allocaInst->use_begin();
                  User *user = use->getUser();
                  // Discovering the opcode of the instruction
                  Instruction* userInst = dyn_cast<Instruction>(user);
                  // Identify variable not initialized by the user;
                  int result = strncmp(userInst->getOpcodeName(), "load", 4);
                  if( result == 0){
                    errs() << userInst->getOpcodeName() << " \n";
                    errs() << "Instruction: " << *allocaInst << "\n";
                    codeupdate = true;
                  }
                  
                  
                }
                
                
                

                // Chain def example
                /*Value *value = nullptr;
                for (Use &use: allocaInst->uses())
                {
                    //assert(use.get() == inst);
                    User *user = use.getUser();
                    unsigned n = use.getOperandNo();
                    Instruction* userInst = dyn_cast<Instruction>(user);
                    value = userInst->getOperand(n);

                    errs() << n << "--" << *value << "\n";
                    break;
                }*/

                // get https://stackoverflow.com/questions/59479206/llvm-retrieve-name-of-allocainst

             }           
            }
          }
          if(codeupdate){
            return true;
          } 
        }
               
        return false;
    }
 };
}

char ListFunctPass::ID = 0;
static RegisterPass<ListFunctPass> X("opInitVarPass", "Initialize Var on main with nondet functions");
