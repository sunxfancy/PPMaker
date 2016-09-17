PPMaker
============

A lexer and parser table maker

## Build

platform: Linux or Mac 
deps: git cmake-2.8 googletest

To install googletest, you can run the script:
```sh
    sh scripts/install_gtest.sh
```


## Using

You need two configures, which has defined the lexer rules and grammer rules in regexes and BNFs.

Here is a demo for lexer rules:
```
    int=[0-9]+
    float=[0-9]*\.[0-9]*
    id=[a-zA-Z_]\w*
    opta= \+=|\-=
    optb= =
    optc= [*/]
    optd= [+\-]
    opte= >|<|<=|>=|==|!=
    other=[(){},;:]
    ignore=\s+
```
