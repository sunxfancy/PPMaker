
#include "Node.h"

void* __ppp_script(int x) {
	switch(x) {
case 0:{
Node* v = (Node*)getArgs(0);
 setRoot(getList(v)) 
return nullptr;
}
case 1:{
Node* pname = (Node*)getArgs(1);
 return pname; 
return nullptr;
}
case 2:{
char* name = (char*)getArgs(0);
 return name.val; 
return nullptr;
}
case 3:{
Node* before = (Node*)getArgs(0);
char* name = (char*)getArgs(2);
 return before + "." + name.val; 
return nullptr;
}
case 4:{
 return "module" 
return nullptr;
}
case 5:{
 return "class" 
return nullptr;
}
case 6:{
 return "struct" 
return nullptr;
}
case 7:{
Node* key = (Node*)getArgs(0);
char* name = (char*)getArgs(1);
Node* def = (Node*)getArgs(2);

                            return makeList(newIDNode(key), newIDNode(name.val), def);
                        
return nullptr;
}
case 8:{
Node* key = (Node*)getArgs(0);
char* name = (char*)getArgs(1);

                            return makeList(newIDNode(key), newIDNode(name.val), newNode());
                        
return nullptr;
}
case 9:{
 return "static"; 
return nullptr;
}
case 10:{
 return "extern"; 
return nullptr;
}
case 11:{
 return "virtual"; 
return nullptr;
}
case 12:{
 return "abstract"; 
return nullptr;
}
case 13:{
 return "in"; 
return nullptr;
}
case 14:{
 return "out"; 
return nullptr;
}
case 15:{
Node* n = (Node*)getArgs(0);
 return newIDNode(n); 
return nullptr;
}
case 16:{
Node* l = (Node*)getArgs(0);
Node* n = (Node*)getArgs(1);
 addBrother(l, newIDNode(n));  return l; 
return nullptr;
}
case 17:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 18:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 19:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 20:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 21:{
char* v = (char*)getArgs(1);
 return v; 
return nullptr;
}
case 22:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 23:{
Node* xs = (Node*)getArgs(0);
char* def = (char*)getArgs(1);
 addBrother(def, newParent(xs)); return def; 
return nullptr;
}
case 24:{
Node* v = (Node*)getArgs(0);
 return getList(v); 
return nullptr;
}
case 25:{
Node* l = (Node*)getArgs(0);
Node* v = (Node*)getArgs(1);
 addBrother(l, getList(v)); return l; 
return nullptr;
}
case 26:{
Node* v = (Node*)getArgs(0);
 return getList(v) 
return nullptr;
}
case 27:{
Node* l = (Node*)getArgs(0);
Node* v = (Node*)getArgs(1);
 addBrother(l, getList(v)); return l; 
return nullptr;
}
case 28:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 29:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 30:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 31:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 32:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 33:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 34:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 35:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 36:{
Node* v = (Node*)getArgs(0);
 return v; 
return nullptr;
}
case 37:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 38:{
 return makeList(newIDNode("break")) 
return nullptr;
}
case 39:{
 return makeList(newIDNode("continue")) 
return nullptr;
}
case 40:{
char* exp = (char*)getArgs(2);
Node* s = (Node*)getArgs(4);
 return makeList(newIDNode("if"), exp, s) 
return nullptr;
}
case 41:{
char* exp = (char*)getArgs(2);
Node* s = (Node*)getArgs(4);
Node* s2 = (Node*)getArgs(6);

                return makeList(newIDNode("if"), exp, s, s2);
            
return nullptr;
}
case 42:{
char* exp = (char*)getArgs(2);
Node* s = (Node*)getArgs(4);
 return makeList(newIDNode("while"), exp, s); 
return nullptr;
}
case 43:{
Node* s = (Node*)getArgs(1);
char* exp = (char*)getArgs(4);
 return makeList(newIDNode("dowhile"), s, exp); 
return nullptr;
}
case 44:{
Node* s = (Node*)getArgs(1);
char* exp = (char*)getArgs(4);
 return makeList(newIDNode("dountil"), s, exp); 
return nullptr;
}
case 45:{
char* init = (char*)getArgs(2);
char* pd = (char*)getArgs(4);
char* work = (char*)getArgs(6);
Node* s = (Node*)getArgs(8);
 return makeList(newIDNode("for"), init, pd, work, s); 
return nullptr;
}
case 46:{
char* init = (char*)getArgs(2);
char* pd = (char*)getArgs(4);
char* work = (char*)getArgs(6);
Node* s = (Node*)getArgs(8);
 return makeList(newIDNode("for"), init, pd, work, s); 
return nullptr;
}
case 47:{
 return newIDNode("return") 
return nullptr;
}
case 48:{
char* exp = (char*)getArgs(1);
l = newIDNode("return"); addBrother(l, getList(exp)); return l;
return nullptr;
}
case 49:{
char* id = (char*)getArgs(1);
char* args = (char*)getArgs(3);
 l = makeList(newIDNode("woven"), newIDNode(id.val)); addBrother(l, args); return l;
return nullptr;
}
case 50:{
Node* s = (Node*)getArgs(1);
 return newParent(s) 
return nullptr;
}
case 51:{
 return newNode(); 
return nullptr;
}
case 52:{
char* id = (char*)getArgs(0);
 return newTypeNode(id.val, false, false); 
return nullptr;
}
case 53:{
char* id = (char*)getArgs(1);
 return newTypeNode(id.val, true, false); 
return nullptr;
}
case 54:{
char* id = (char*)getArgs(1);
 return newTypeNode(id.val, false, true); 
return nullptr;
}
case 55:{
char* id = (char*)getArgs(2);
 return newTypeNode(id.val, true, true); 
return nullptr;
}
case 56:{
char* t = (char*)getArgs(0);
 addDimension(t); return t; 
return nullptr;
}
case 57:{
char* t = (char*)getArgs(0);
char* id = (char*)getArgs(1);
 return makeList(newIDNode("set"), t, newIDNode(id.val)); 
return nullptr;
}
case 58:{
char* t = (char*)getArgs(0);
char* id = (char*)getArgs(1);
char* init = (char*)getArgs(3);

            return makeList(newIDNode("set"), t, newIDNode(id.val), init); 
return nullptr;
}
case 59:{
char* id = (char*)getArgs(0);
 return newIDNode(id.val); 
return nullptr;
}
case 60:{
char* args = (char*)getArgs(0);
char* id = (char*)getArgs(2);
 addBrother(args, newIDNode(id.val));  return args; 
return nullptr;
}
case 61:{
char* id = (char*)getArgs(1);
char* args = (char*)getArgs(3);
Node* b = (Node*)getArgs(5);
return makeList(newIDNode("defmacro"), newIDNode(id.val), args, b);
return nullptr;
}
case 62:{
char* id = (char*)getArgs(1);
 return newIDNode(id.val); 
return nullptr;
}
case 63:{
char* m = (char*)getArgs(0);
char* args = (char*)getArgs(2);
 addBrother(m, args); return m; 
return nullptr;
}
case 64:{
char* m = (char*)getArgs(0);
Node* b = (Node*)getArgs(1);
 addBrother(m, getList(b)); return m; 
return nullptr;
}
case 65:{
char* m = (char*)getArgs(0);
char* id = (char*)getArgs(1);
Node* b = (Node*)getArgs(2);
 addBrother(m, newIDNode(id.val)); addBrother(m, getList(b)); return m; 
return nullptr;
}
case 66:{
char* t = (char*)getArgs(0);
Node* id = (Node*)getArgs(1);
char* args = (char*)getArgs(3);
Node* b = (Node*)getArgs(5);
 return makeList(newIDNode("function"), t, newIDNode(id), args, b); 
return nullptr;
}
case 67:{
char* t = (char*)getArgs(0);
Node* id = (Node*)getArgs(1);
char* args = (char*)getArgs(3);
 return makeList(newIDNode("function"), t, newIDNode(id), args, newNode()); 
return nullptr;
}
case 68:{
char* v = (char*)getArgs(0);
 return newParent(newParent(v)); 
return nullptr;
}
case 69:{
char* args = (char*)getArgs(0);
char* v = (char*)getArgs(2);
 addChildren(args, newParent(v)); return args; 
return nullptr;
}
case 70:{
 return newNode(); 
return nullptr;
}
case 71:{
char* t = (char*)getArgs(1);
 return makeList(newIDNode("new"), t, newNode()); 
return nullptr;
}
case 72:{
char* t = (char*)getArgs(1);
char* args = (char*)getArgs(3);
 return makeList(newIDNode("new"), t, newParent(args)); 
return nullptr;
}
case 73:{
char* n = (char*)getArgs(0);
char* args = (char*)getArgs(2);
 addBrother(n, newParent(args)); return n;
return nullptr;
}
case 74:{
char* exp = (char*)getArgs(1);
 return make_list(newIDNode("delete"), exp); 
return nullptr;
}
case 75:{
char* exp = (char*)getArgs(2);
 return make_list(newIDNode("delete[]"), exp); 
return nullptr;
}
case 76:{
char* i = (char*)getArgs(0);
 return newIntNode(i.val); 
return nullptr;
}
case 77:{
char* f = (char*)getArgs(0);
 return newFloatNode(f.val); 
return nullptr;
}
case 78:{
char* id = (char*)getArgs(0);
 return newIDNode(id.val); 
return nullptr;
}
case 79:{
char* n = (char*)getArgs(0);
 return n; 
return nullptr;
}
case 80:{
char* s = (char*)getArgs(0);
 return newStringNode(s.val); 
return nullptr;
}
case 81:{
 return newIDNode("null"); 
return nullptr;
}
case 82:{
 return newIDNode("true"); 
return nullptr;
}
case 83:{
 return newIDNode("false"); 
return nullptr;
}
case 84:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("="), e1, e2); 
return nullptr;
}
case 85:{
char* e1 = (char*)getArgs(0);
char* args = (char*)getArgs(2);
 l = makeList(newIDNode("call"), e1); if args then addBrother(l, args); end; return l; 
return nullptr;
}
case 86:{
char* e1 = (char*)getArgs(0);
char* args = (char*)getArgs(2);
 l = makeList(newIDNode("select"), e1); if args then addBrother(l, args); end; return l; 
return nullptr;
}
case 87:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 88:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 89:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("=="), e1, e2); 
return nullptr;
}
case 90:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("!="), e1, e2); 
return nullptr;
}
case 91:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("<="), e1, e2); 
return nullptr;
}
case 92:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode(">="), e1, e2); 
return nullptr;
}
case 93:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("&&"), e1, e2); 
return nullptr;
}
case 94:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("||"), e1, e2); 
return nullptr;
}
case 95:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode(">="), e1, e2); 
return nullptr;
}
case 96:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("<"), e1, e2); 
return nullptr;
}
case 97:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode(">"), e1, e2); 
return nullptr;
}
case 98:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(3);
 return makeList(newIDNode("opt2"), newIDNode("<<"), e1, e2); 
return nullptr;
}
case 99:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(3);
 return makeList(newIDNode("opt2"), newIDNode(">>"), e1, e2); 
return nullptr;
}
case 100:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("+"), e1, e2); 
return nullptr;
}
case 101:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("-"), e1, e2); 
return nullptr;
}
case 102:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("*"), e1, e2); 
return nullptr;
}
case 103:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("/"), e1, e2); 
return nullptr;
}
case 104:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("%"), e1, e2); 
return nullptr;
}
case 105:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("^"), e1, e2); 
return nullptr;
}
case 106:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("&"), e1, e2); 
return nullptr;
}
case 107:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("|"), e1, e2); 
return nullptr;
}
case 108:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("+="), e1, e2); 
return nullptr;
}
case 109:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("-="), e1, e2); 
return nullptr;
}
case 110:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("*="), e1, e2); 
return nullptr;
}
case 111:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("/="), e1, e2); 
return nullptr;
}
case 112:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("%="), e1, e2); 
return nullptr;
}
case 113:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("^="), e1, e2); 
return nullptr;
}
case 114:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("&="), e1, e2); 
return nullptr;
}
case 115:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("|="), e1, e2); 
return nullptr;
}
case 116:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("<<="), e1, e2); 
return nullptr;
}
case 117:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode(">>="), e1, e2); 
return nullptr;
}
case 118:{
char* e1 = (char*)getArgs(0);
char* e2 = (char*)getArgs(2);
 return makeList(newIDNode("opt2"), newIDNode("."), e1, e2); 
return nullptr;
}
case 119:{
char* e1 = (char*)getArgs(1);
 return makeList(newIDNode("opt1"), newIDNode("-"), e1) 
return nullptr;
}
case 120:{
char* e1 = (char*)getArgs(1);
 return makeList(newIDNode("opt1"), newIDNode("~"), e1) 
return nullptr;
}
case 121:{
char* e1 = (char*)getArgs(1);
 return makeList(newIDNode("opt1"), newIDNode("!"), e1) 
return nullptr;
}
case 122:{
char* e1 = (char*)getArgs(1);
 return makeList(newIDNode("opt1"), newIDNode("++"), e1) 
return nullptr;
}
case 123:{
char* e1 = (char*)getArgs(1);
 return makeList(newIDNode("opt1"), newIDNode("--"), e1) 
return nullptr;
}
case 124:{
char* e1 = (char*)getArgs(0);
 return makeList(newIDNode("opt1"), newIDNode("b++"), e1) 
return nullptr;
}
case 125:{
char* e1 = (char*)getArgs(0);
 return makeList(newIDNode("opt1"), newIDNode("b--"), e1) 
return nullptr;
}
case 126:{
char* e1 = (char*)getArgs(1);
 return e1; 
return nullptr;
}
case 127:{
char* e1 = (char*)getArgs(0);
 return e1; 
return nullptr;
}
case 128:{
char* id = (char*)getArgs(0);
char* e1 = (char*)getArgs(2);
 return makeList(newIDNode("="), id.val, e1); 
return nullptr;
}
case 129:{
 return newNull(); 
return nullptr;
}
case 130:{
char* arg = (char*)getArgs(0);
 return getList(arg); 
return nullptr;
}
case 131:{
char* args = (char*)getArgs(0);
char* arg = (char*)getArgs(2);
 addBrother(args, getList(arg)); return args; 
return nullptr;
}
case 132:{
 return newNode(); 
return nullptr;
}
case 133:{
char* arg = (char*)getArgs(0);
 return getList(arg); 
return nullptr;
}
case 134:{
char* m = (char*)getArgs(0);
 return getList(m); 
return nullptr;
}
case 135:{
char* args = (char*)getArgs(0);
char* arg = (char*)getArgs(2);
 addBrother(args, getList(arg)); return args; 
return nullptr;
}
case 136:{
char* args = (char*)getArgs(0);
char* m = (char*)getArgs(2);
 addBrother(args, getList(m)); return args; 
return nullptr;
}
case 137:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 138:{
char* v = (char*)getArgs(0);
 return v; 
return nullptr;
}
case 139:{
char* v = (char*)getArgs(1);
 return v; 
return nullptr;
}
case 140:{
char* l = (char*)getArgs(0);
char* v = (char*)getArgs(1);
 addBrother(l, v); return l; 
return nullptr;
}
case 141:{
char* l = (char*)getArgs(0);
char* v = (char*)getArgs(1);
 addBrother(l, v); return l; 
return nullptr;
}
case 142:{
char* l = (char*)getArgs(0);
char* v = (char*)getArgs(2);
 addBrother(l, v); return l; 
return nullptr;
}
case 143:{
char* l = (char*)getArgs(1);
 return newParent(l); 
return nullptr;
}
	default: return nullptr;
	}
}
