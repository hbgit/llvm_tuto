#include <llvm-8/llvm/ADT/STLExtras.h>
#include <llvm-8/llvm/IR/BasicBlock.h>
#include <llvm-8/llvm/IR/Instruction.h>
#include <llvm-8/llvm/IR/Use.h>
#include <llvm-8/llvm/IR/Value.h>
#include <llvm-8/llvm/Support/Casting.h>

#define DEBUG_TYPE "opAddFunctPass"

#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/InstIterator.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Metadata.h>
#include <llvm/Pass.h>
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

      // int __MY_INT(void);
      Constant *funct;
      //= F.getParent()->getOrInsertFunction("__MY_INT", Type::getInt32Ty(Ctx));
      

      // Running each basic block
      for (auto &bb : F) {
        // Looking for the instructions
        for (auto &instruction : bb) {
          // For each Alloca instructions one Store should be
          // found, if not that Alloca was not initialized
          if (auto *al = dyn_cast<AllocaInst>(&instruction)) {

            errs() << "Instruction: " << *al << " is used " << al->getNumUses()
                   << " times \n";
            //errs() << al->getAllocatedType()->isIntegerTy() << "\n";

            // This because of backtracking def-use chain searching
            // https://stackoverflow.com/questions/35370195/llvm-difference-between-uses-and-user-in-instruction-or-value-classes
            if (al->getNumUses() > 0){

                al->reverseUseList();

                // We need the first use from instruction
                // to check if is an store instruction
                if( auto *inst = dyn_cast<LoadInst>(al->uses().begin()->getUser()) ){
                      errs() << *al->uses().begin()->getUser() << "\n";
                      errs() << "Is not a store instruction"
                            << "\n";

                      // Now we create a callinst instruction
                      // to be inserted before this instruction
                      errs() << *inst << "\n";
                      IRBuilder<> builder(reinterpret_cast<Instruction *>(inst));
                      builder.SetInsertPoint(&bb, builder.GetInsertPoint());

                      // Identify the variable type                     
                      if(al->getAllocatedType()->isIntegerTy()){
                          errs() << "Is Interger \n";
                          funct = F.getParent()->getOrInsertFunction("__MY_INT", Type::getInt32Ty(Ctx));
                          Function *hook = cast<Function>(funct);
                          // Create Call Inst to void __TRACK(void);
                          auto *cInst =
                              builder.CreateCall(hook, None, "tmp_1_my_call", NULL);

                          // Create a store instruction
                          builder.SetInsertPoint(&bb, builder.GetInsertPoint());
                          builder.CreateStore(cInst, al);
                      }

                }
              }

            // return true;
          }
        }
      }
    }

    return false;
  }
};
} // namespace

char ListFunctPass::ID = 0;
static RegisterPass<ListFunctPass> X("opAddFunct2VarPass", "Add functions");
