extern char lex_data[]      __asm__ ("_binary_lex_cfg_lexsave_start");
extern char lex_data_end[]  __asm__ ("_binary_lex_cfg_lexsave_end");

extern char parser_data[]  __asm__ ("_binary_parser_cfg_lrsave_start");
extern char parser_data_end[]  __asm__ ("_binary_parser_cfg_lrsave_end");

typedef const char* (*getLexTable_t)();
typedef const char* (*getLALRTable_t)();

extern const char* getLexTable() {
    return lex_data;
}

extern const char* getLALRTable() {
    return parser_data_end;
}
