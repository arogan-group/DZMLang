// (c) ZaKlaus 2016; All Rights Reserved;;

#if !defined(DZM_REP_H)

void
test_load_file(char *Name)
{
    FILE *File = fopen(Name, "r");
    
    if(File == 0)
    {
        fprintf(stderr, "File not found\n");
        exit(1);
    }
    OBJECT *Exp;
    while(1)
    {
        Exp = read(File);
        if(Exp == 0)
        {
            break;
        }
        write(stdout, eval(Exp, GlobalEnv));
    }
    fclose(File);
}

void
test_repl(void)
{
    printf("DZMLang REPL; By ZaKlaus.\nUse ^C to exit.\n");
    
    //init_defs();
    
    for(;;)
    {
        printf(": ");
        write(stdout, eval(read(stdin), GlobalEnv));
        printf("\n");
    }
}

void
test_init(int argc, char** argv)
{
    if(argc < 2)
    {
        init_defs();
        
        test_load_file("stdlib.dzm");
        
        test_repl();
        return;
    }
    printf("DZMLang Interpreter; By ZaKlaus.\n");
    
    test_load_file(argv[1]);
}

#define DZM_REP_H
#endif