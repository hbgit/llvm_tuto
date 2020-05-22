#define DEBUG_TYPE "oplistFunctPass"

#include <llvm/Pass.h>
#include <llvm/IR/Function.h> 
#include <llvm/IR/InstIterator.h>
#include <llvm/IR/Instructions.h>
#include <llvm/Support/raw_ostream.h> 
#include <map>

using namespace llvm;
namespace {
  
  struct ListFunctPass : public FunctionPass {
   
    static char ID;   
    ListFunctPass() : FunctionPass(ID) {}
    
    virtual bool runOnFunction(Function &F) {
        //errs() << "Function " << F.getName() << '\n';
        for (auto &bb : F) {
          for (auto &instruction : bb) {
            //errs() << instruction << "\n";
            if (CallInst *callInst = dyn_cast<CallInst>(&instruction)) {
              if (Function *calledFunction = callInst->getCalledFunction()) {
                if (calledFunction->getName().startswith("__VERIFIER_nondet")) {
                  errs() << calledFunction->getName() << "\n";
                }
              }
            }
          }
        }        
        return false;
    }
 };
}

char ListFunctPass::ID = 0;
static RegisterPass<ListFunctPass> X("oplistFunctPass", "Identify nondet functions");
