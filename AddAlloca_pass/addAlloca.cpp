#define DEBUG_TYPE "opAddAllocaPass"

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
        
        // Look for main function
        if (F.getName() == "main") {  

          // Getting LLVM context from function
          LLVMContext &Ctx = F.getContext();   
          
          // Running for each Basic Block
          for (auto &bb : F) {
            // Running for each instruction
            for (auto &instruction : bb) {
              // Look for BinaryOperator instruction
              if ( auto *op = dyn_cast<BinaryOperator>(&instruction) ) {              

                // Creating alloca instruction:                
                // AllocaInst(Type *Ty, unsigned AddrSpace, Value *ArraySize, unsigned Align,
                //            const Twine &Name = "", Instruction *InsertBefore = nullptr);
                AllocaInst* pa = new AllocaInst(Type::getInt32Ty(Ctx), 0, NULL, 4, "tmp_1", op);                                

                return true;

             }
            }
          }
        }
               
          return false;
    }
  };
}

char ListFunctPass::ID = 0;
static RegisterPass<ListFunctPass> X("opAddAllocaPass", "Add AllocaInst");
