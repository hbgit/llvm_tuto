#define DEBUG_TYPE "opAddFunctPass"

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

          LLVMContext &Ctx = F.getContext();
          //return int
          // Constant* funct = F.getParent()->getOrInsertFunction("__TRACK", Type::getInt32Ty(Ctx));
          // void __TRACK(void);
          Constant* funct = F.getParent()->getOrInsertFunction("__TRACK", Type::getVoidTy(Ctx));
          Function *hook = cast<Function>(funct);

          // Running each basic block
          for (auto &bb : F) {
            // Looking for the instructions
            for (auto &instruction : bb) {
              // BinaryOperator instructions
             if ( auto *op = dyn_cast<BinaryOperator>(&instruction) ) { 
                
                IRBuilder<> builder(reinterpret_cast<Instruction*>(op));  
                // To insert after this instruction
                builder.SetInsertPoint(&bb, ++builder.GetInsertPoint());
                // Create Call Inst to void __TRACK(void);
                builder.CreateCall(hook, None, "", NULL);

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
static RegisterPass<ListFunctPass> X("opAddFunctPass", "Add functions");
