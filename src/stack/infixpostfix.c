// infix: a+b; postfix: ab+
// example x-y*z to post fix, first parenthesize it: (x-(y*z))
// (x-[yz*]) --> use [] to show that the given part has been converted
// xyz*-
// it is evaluated as:
// first go from x to z, then look at the first operator
// first operator is * and the operands are y and z so do y*z
// then the next operator is - and the operands are x and yz
// so do x - yz
#include <stdio.h>
int main() {
  return 0;
}
