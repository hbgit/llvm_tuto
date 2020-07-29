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
      Constant *funct =
          F.getParent()->getOrInsertFunction("__MY_INT", Type::getInt32Ty(Ctx));
      Function *hook = cast<Function>(funct);

      // Running each basic block
      for (auto &bb : F) {
        // Looking for the instructions
        for (auto &instruction : bb) {
          // For each Alloca instructions one Store should be
          // found, if not that Alloca was not initialized
          if (auto *al = dyn_cast<AllocaInst>(&instruction)) {

            errs() << "Instruction: " << *al << " is used " << al->getNumUses()
                   << " times \n";

            
            
            // errs() << *al->uses()-> << "\n";
            // errs() << *al->users().begin().getUse().get() << "\n";

            /*for (auto U : al->users() ) { // U is of type User*
              if (auto I = dyn_cast<Instruction>(U)) {
                // an instruction uses al
                errs() << *I << "\n";
              }
            }*/

            al->reverseUseList();
            errs() << *al->uses().begin()->getUser() << "\n";
            
            //errs() << *al->uses().end()->getUser(). << "\n";
            

            
            /*errs() << "1 :::: ======================================== \n";
            // def-use chain:
            //
            https://stackoverflow.com/questions/35370195/llvm-difference-between-uses-and-user-in-instruction-or-value-classes
            for (Value::use_iterator i = al->use_begin(), e = al->use_end();
                 i != e; ++i) {

              // if(Instruction *inst = dyn_cast<Instruction>(i->get())){
              errs() << &*i << "\n";
              //}

              // errs() << ">> " << *i->getUser() << "\n";
            }*/

            // However we need the first use from instruction
            // to check if is an store instruction
            // errs() << "   >> First match only: " <<
            //       *al->user_back() << "\n";
            // if(al->use_begin()->getUser()){

            //}

            // errs() << *ld->getPointerOperand() << "\n";

            // IRBuilder<> builder(reinterpret_cast<Instruction*>(ld));
            // To insert after this instruction
            // builder.SetInsertPoint(&bb, builder.GetInsertPoint());
            // Create Call Inst to void __TRACK(void);
            // builder.CreateCall(hook, None, "", NULL);

            // Create a store instruction

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
