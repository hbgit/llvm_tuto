

#include <llvm/Pass.h>
#include <llvm/IR/Function.h> 
#include <llvm/IR/IRBuilder.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/Support/raw_ostream.h> 

#include <llvm/ADT/Statistic.h>
#include <llvm/IR/InstIterator.h>
#include <llvm/IR/Instructions.h>
#include <llvm/Analysis/LoopInfo.h>


#include <map>
#include <vector>
#include <iostream>

using namespace llvm;
using namespace std;



namespace{

    inline Instruction* BBIteratorToInst(BasicBlock::iterator i) {                                                                                    
        Instruction* pointer = reinterpret_cast<Instruction*>(&*i);
        return pointer;
  }           


	struct	FPredLoppPass : public FunctionPass{
		static	char ID;
        Function* currentFunction;
        LLVMContext* Ctx;

        Constant* map2check_assume = NULL;

		FPredLoppPass():FunctionPass(ID){}
		
		void getAnalysisUsage(AnalysisUsage &AU) const override{
			AU.setPreservesAll();
			AU.addRequired<LoopInfoWrapperPass>();
		}
		
		void getConditionInLoop(Loop *L){
			Loop::block_iterator bb;
            errs() << "teste \n";
            BasicBlock* header = L->getHeader();
            errs() << "teste \n";


            if (BranchInst *bi = dyn_cast<BranchInst>(header->getTerminator())) {

                errs() << "IF 1\n";
               if(bi->isConditional()){
                errs() << *bi->getCondition() << "\n";                
                errs() << "bi \n";
                Value *loopCond = bi->getCondition();                
                errs() << *loopCond << "\n";

                CmpInst *cmpInst = dyn_cast<CmpInst>(&*loopCond);                
                errs() << "Antes test \n";

                if( bi->getNumSuccessors() > 0 && bi->isConditional()){
                //if( bi->isConditional() ){

                    errs() << "here \n";
                    BasicBlock* succ_cond_bb = bi->getSuccessor(1);
                    //errs() << *succ_cond_bb->getFirstNonPHI() << "\n";
                    //errs() << "^ non phi \n";
                    BasicBlock::iterator iT = succ_cond_bb->begin();

                    Instruction inst_pos_an;

			        for(BasicBlock::iterator i = succ_cond_bb->begin(), e = succ_cond_bb->end(); i != e; ++i)
                    {
                        //identificar cmpinst ou call funct para instrumentar o assume antes
                    }


                    auto *new_inst = cmpInst->clone();
                    auto *inst_pos = dyn_cast<Instruction>(&*succ_cond_bb->begin());
                    errs() << *inst_pos << "\n";
                    new_inst->insertBefore(inst_pos);
                    
                    CmpInst *new_cmpInst = dyn_cast<CmpInst>(&*new_inst);
                    new_cmpInst->setPredicate(new_cmpInst->getInversePredicate());

                    Value *new_loop_cond = dyn_cast<Value>(&*new_cmpInst); // Convert CmpInst to Value;
                    
                    IRBuilder<> builder(BBIteratorToInst(iT));                                        

                    //e.g., call function map2check_assume(a < b)
                    this->map2check_assume = this->currentFunction->getParent()->getOrInsertFunction(
                                             "map2check_assume",
                                            Type::getVoidTy(this->currentFunction->getContext()),
                                            Type::getInt1Ty(this->currentFunction->getContext()), NULL
                                            );

                    Value* args[] = {new_loop_cond};                    
                    builder.CreateCall(this->map2check_assume, args);


                }
            }

               }
			
		}
		
		virtual	bool runOnFunction(Function &F) override{
            this->Ctx = &F.getContext();
			LoopInfo &LI = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
			errs() << "Function " << F.getName() + "\n";
            this->currentFunction = &F;
			for(LoopInfo::iterator i = LI.begin(), e = LI.end(); i != e; ++i)
				getConditionInLoop(*i);
			
			return(false);
		}
	};
}

char FPredLoppPass::ID = 0; static RegisterPass<FPredLoppPass> X("predloop", "Get all loops predicates");
