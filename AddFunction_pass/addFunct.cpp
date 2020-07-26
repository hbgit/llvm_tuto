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
        
        
        if (F.getName() == "main") {

          LLVMContext &Ctx = F.getContext();
          Constant* map2check_exit = F.getParent()->getOrInsertFunction("map2check_success", Type::getInt32Ty(Ctx));
          Function *hook = cast<Function>(map2check_exit);

          //Constant* map2check_exit = F.getParent()->getOrInsertFunction("map2check_success", Type::getVoidTy(Ctx));
          // for void just is necessary 
          // builder.SetInsertPoint(&bb, ++builder.GetInsertPoint());
          // builder.CreateCall(map2check_exit);


          /*
          std::vector<Type*> paramTypes = {Type::getInt32Ty(Ctx)};
          Type *retType = Type::getVoidTy(Ctx);
          FunctionType *logFuncType = FunctionType::get(retType, paramTypes, false);
          Constant *logFunc = F.getParent()->getOrInsertFunction("__VERIFIER_nondet_int", logFuncType);
          bool codeupdate = false;*/

          // Identify all variables
          for (auto &bb : F) {
            for (auto &instruction : bb) {
             if ( auto *op = dyn_cast<BinaryOperator>(&instruction) ) { 
                
            
                Instruction *newInst = CallInst::Create(hook, "call_tmp");
                IRBuilder<> builder(reinterpret_cast<Instruction*>(&instruction));  
                bb.getInstList().insert(builder.GetInsertPoint()++, newInst);



                
                
                
                // Insert Before the instruction
                //IRBuilder<> builder(reinterpret_cast<Instruction*>(&instruction));
                //instruction.getParent()->getOrInsertFunction("map2check_success", Type::getVoidTy(Ctx));
                //CallInst ca = new CallInst();
                
                /*
                AllocaInst* pa = new AllocaInst(Type::getInt32Ty(Ctx), 0, "temp1", op);                
                bb.getInstList().insert(builder.GetInsertPoint(), map2check_exit); 

                // Insert After the instruction
                builder.SetInsertPoint(&bb, ++builder.GetInsertPoint());
                builder.CreateCall(map2check_exit);

                // Create a store instruction to call the function
                // i -> current instruction pointer which represents %add ( source of store instruction ), 
                // pa -> destination. i.e., temp1
                AllocaInst* pa = new AllocaInst(Type::getInt32Ty(Ctx), 0, "temp2", op);                
                StoreInst *str = new StoreInst(op, pa); 
                // ib -> instruction address before which you want to insert this store instruction
                bb.getInstList().insert(builder.GetInsertPoint()++, str); */

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
