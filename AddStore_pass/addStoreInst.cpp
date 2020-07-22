#define DEBUG_TYPE "opAddStoreInstPass"

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
            for (BasicBlock::iterator i = bb.begin(), ie = bb.end(); i != ie; ++i) {

              Instruction* pointer = reinterpret_cast<Instruction*>(&*i);

              // Look for BinaryOperator instruction
              if ( auto *op = dyn_cast<BinaryOperator>(pointer) ) {   

                Instruction* pointer_2 = reinterpret_cast<Instruction*>(&*++i);           
                               
                // Creating alloca instruction:                
                // AllocaInst(Type *Ty, unsigned AddrSpace, Value *ArraySize, unsigned Align,
                //            const Twine &Name = "", Instruction *InsertBefore = nullptr);
                AllocaInst* pa = new AllocaInst(Type::getInt32Ty(Ctx), 0, NULL, 4, "tmp_1", pointer_2);
                //AllocaInst::Create(Type::getInt32Ty(Ctx), 0, NULL, 4, "tmp_1")->insertAfter(op);
                //bb.getInstList().insert(builder.GetInsertPoint()++, pa); 
                //bb.getInstList().insert(builder.GetInsertPoint(), str);                          
                //IRBuilder<> builder(reinterpret_cast<Instruction*>(pa)); 

                Instruction* pointer_3 = reinterpret_cast<Instruction*>(&*++i);  

                StoreInst *str = new StoreInst(op, pa, pointer_3);   
                
                //bb.getInstList().insert(builder.GetInsertPoint(), str);                          

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
