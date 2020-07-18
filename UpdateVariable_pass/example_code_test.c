extern int __VERIFIER_nondet_int(void);
extern int __VERIFIER_nondet_double(void);

#include <stddef.h>

int bar(){
  int a = __VERIFIER_nondet_int(); 
  return a;
}

void foo() {
  int N = bar();
  int i =0;
  for(i = 0; i<= N; i++){
    if(i > 1){
      double k = __VERIFIER_nondet_double();
    }

  }
}

int main(){
  foo();

  int *p = NULL;
  
  int b;

  unsigned int a;

  double d;

  b = a;

  return 0;
}
