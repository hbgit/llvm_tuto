#CXX := clang++ `llvm-config --cxxflags`
#CC := clang

CXX := g++
CXXFLAGS := -fno-rtti -O0 -g
PLUGIN_CXXFLAGS := -fpic

LLVM_CXXFLAGS := `llvm-config --cxxflags`
LLVM_LDFLAGS  := `llvm-config --ldflags --libs --system-libs`

# Internal paths in this project: where to find sources, and where to put
# build artifacts.
SRC_LLVM_DIR := src_llvm
BUILDDIR := build


.PHONY: all
all: make_builddir \
		$(BUILDDIR)/main \


.PHONY: make_builddir
make_builddir:
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
		

$(BUILDDIR)/main: $(SRC_LLVM_DIR)/main/main.cpp			
			$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $^ $(LLVM_LDFLAGS) -o $@




.PHONY: clean
clean:
	rm -rf $(BUILDDIR)/*
