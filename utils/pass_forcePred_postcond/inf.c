void myexit(int s) {
 _EXIT: goto _EXIT;
}

main()
{
    myexit(1);
}
