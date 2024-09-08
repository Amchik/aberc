#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help(void) {
    /* idontcare */
    puts("aberc --- Simple aber language interpreter and repl");
    puts("");
    puts("SYNOPSIS: aberc <filename | \"--repl\">");
    puts("");
    puts("    --repl      Runs interactive repl");
    puts("    filename    Aber file to run");
    puts("");
    puts("More documentation: <https://github.com/Hedgehogo/aber.io>");
}

void unsupported(void) {
    puts("Executing file is unsupported in this version of aberc.");
    puts("But you can use --repl flag and pass code from stdin:");
    puts(" $ aberc --repl < filename.aber");
}

int main(int argc, char **argv) {
    if (argc < 2 || !strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
        help();
        return argc >= 2;
    }

    if (!strcmp(argv[1], "--repl")) {
#ifdef _WIN32
        system("start https://chatgpt.com");
#elif __linux__
        system("xdg-open https://chatgpt.com");
#endif
    } else {
        unsupported();
        return 1;
    }

    return 0;
}
