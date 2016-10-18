extern char lex_data[]      __asm__ ("_binary_lex_cfg_lexsave_start");
extern char lex_data_end[]  __asm__ ("_binary_lex_cfg_lexsave_end");

extern char parser_data[]  __asm__ ("_binary_parser_cfg_lrsave_start");
extern char parser_data_end[]  __asm__ ("_binary_parser_cfg_lrsave_end");


extern const char* __getLexTable() {
    return lex_data;
}

extern const char* __getLALRTable() {
    return parser_data;
}

extern const char* __getLexTableSize() {
    return lex_data_end - lex_data;
}

extern const char* __getLALRTableSize() {
    return parser_data_end - parser_data;
}
