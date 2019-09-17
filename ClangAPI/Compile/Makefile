CXX := g++
CXXFLAGS := -fno-rtti -O0 -g
PLUGIN_CXXFLAGS := -fpic

LLVM_CXXFLAGS := `llvm-config-6.0 --cxxflags`
LLVM_LDFLAGS  := `llvm-config-6.0 --ldflags --libs --system-libs`

#g++ -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS
#-I/usr/local/Cellar/llvm/3.1/include -L/usr/local/Cellar/llvm/3.1/lib
#-fvisibility-inlines-hidden -lclangAnalysis -lclangAST -lclangBasic
#-lclangCodeGen -lclangDriver -lclangEdit -lclangFrontend -lclangLex
#-lclangParse -lclangRewrite -lclangSema -lclangSerialization
#-lclangTooling -lLLVMAnalysis -lLLVMArchive -lLLVMAsmParser
#-lLLVMAsmPrinter -lLLVMBitReader -lLLVMBitWriter -lLLVMCodeGen -lLLVMCore
#-lLLVMExecutionEngine -lLLVMInstCombine -lLLVMInstrumentation -lLLVMInterpreter
#-lLLVMJIT -lLLVMLinker -lLLVMMC -lLLVMMCParser -lLLVMScalarOpts -lLLVMSelectionDAG
#-lLLVMSupport -lLLVMTarget -lLLVMTransformUtils -lLLVMVectorize -lLLVMX86AsmParser
#-lLLVMX86AsmPrinter -lLLVMX86CodeGen -lLLVMX86Desc -lLLVMX86Info -lLLVMX86Utils
#-lLLVMipa -lLLVMipo -o compile_to_module-return compile_to_module-return.cpp

# Internal paths in this project: where to find sources, and where to put
# build artifacts.
SRC_LLVM_DIR := src
BUILDDIR := build


.PHONY: all
all: make_builddir \
		$(BUILDDIR)/main \


.PHONY: make_builddir
make_builddir:
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)


$(BUILDDIR)/main: $(SRC_LLVM_DIR)/main/compile_to_module-return.cpp
			$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $^ $(LLVM_LDFLAGS) -o $@


.PHONY: clean
clean:
	rm -rf $(BUILDDIR)/*
