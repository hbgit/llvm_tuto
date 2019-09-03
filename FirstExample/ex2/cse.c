void main(int argc, char** argv) {
  char c1 = argc + 1;
  char c2 = argc - 1;
  char c3 = c1 + c2;
  char c4 = c1 + c2;
  char c5 = c4 * 4;
  if (argc % 2)
    printf("Value = %d\n", c3);
  else
    printf("Value = %d\n", c5);
}
