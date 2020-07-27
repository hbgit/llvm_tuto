#define DEBUG_TYPE "opAddStoreInstPass"

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
            for (BasicBlock::iterator i = bb.begin(), ie = bb.end(); i != ie; ++i) {

              Instruction* pointer = reinterpret_cast<Instruction*>(&*i);

              // Look for BinaryOperator instruction
              if ( auto *op = dyn_cast<BinaryOperator>(pointer) ) {   
                
                // API to create and insert instructions
                IRBuilder<> builder(reinterpret_cast<Instruction*>(op)); 
                               
                // Creating alloca instruction:                                
                builder.SetInsertPoint(&bb, ++builder.GetInsertPoint());
                auto *pa = builder.CreateAlloca(Type::getInt32Ty(Ctx),NULL,"tmp_1");

                // Creating store instruction:
                builder.SetInsertPoint(&bb, builder.GetInsertPoint());
                builder.CreateStore(op, pa);                                     

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
static RegisterPass<ListFunctPass> X("opAddStoreInstPass", "Add StoreInst");
