#include <stdint.h>

extern uint8_t lex_data[]     asm("_binary_lex_cfg_lexsave_start");
extern uint8_t lex_data_end[] asm("_binary_lex_cfg_lexsave_end");

extern uint8_t parser_data[]     asm("_binary_parser_cfg_lrsave_start");
extern uint8_t parser_data_end[] asm("_binary_parser_cfg_lrsave_end");

typedef const char* (*getLexTable_t)();
typedef const char* (*getLALRTable_t)();

extern const char* getLexTable() {
    return lex_data;
}

extern const char* getLALRTable() {
    return parser_data_end;
}
