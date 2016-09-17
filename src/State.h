#ifndef STATE_H
#define STATE_H

#include <string>
#include <cereal/types/string.hpp>

using namespace std;

enum StateType
{
      statement, constant , temporality , epsilon , terminal , script
    // 非终结符	 静态常量	临时型	    空	     终结符
};

class State
{
public:
    State();
    State(const State& other);
    ~State();
    State& operator=(const State& other);
    bool operator==(const State& other);

    void init();

    void AddBrotherState(State* _brother);
    void AddChildrenState(State* _children);

    State* children; //此指针列表里放入state的定义项
    State* brother;

    int id;

    const char* state_const;
    const char* state_class;
    const char* state_var;
    char* script;

    enum StateType state_type; // 0为class的声明, 1为常量, 2为临时型, 3为Epsilon

    int Repeatable; // 0 null  1 ?  2 +  3 *

    bool isList = true; //如何是List的话，子列表就是每项依次匹配，否则子列表是（a|b）式或匹配


    // 串行化
private:
    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar)
    {
        // serialize things by passing them to the archive
        string sconst;
        if (state_const != NULL) sconst = state_const;
        string sclass;
        if (state_class != NULL) sclass = state_class;
        string svar;
        if (state_var != NULL) svar = state_var;
        ar( sconst, sclass, svar);
    }
};

#endif // STATE_H
