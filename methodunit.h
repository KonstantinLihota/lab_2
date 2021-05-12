
#pragma once
#include<iostream>
#include<unit.h>
#include<vector>

class MethodUnit : public Unit //Класс обеспечивает логику построения методов  MyClass
{
public:
    enum Modifier { //Модификаторы для всех яп
        PUBLIC      = 1,
        PROTECTED   = 1 << 1,
        PRIVATE     = 1 << 2,
        STATIC      = 1 << 3,
        CONST       = 1 << 4,
        VIRTUAL     = 1 << 5,
        ABSTRACT    = 1 << 6,
        OVERRIDE    = 1 << 7,
        SEALED      = 1 << 8
    };
public:

    MethodUnit(const std::string &name, const std::string &returnType, Flags flags) : m_name(name), m_returnType(returnType), m_flags(flags)
    { }

    void add(const std::shared_ptr<Unit> &unit) {
        m_body.push_back(unit);
    }
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;

protected:

    Flags Get_flags() const { return m_flags; }

    const std::string& Get_returnType() const { return m_returnType; }

    const std::string& Get_name() const { return m_name; }

    const std::vector< std::shared_ptr< Unit > >&Get_Body() const { return m_body; }

};

//конкретные классы для создания методов MyClass
class CMethod : public MethodUnit {
public:
    CMethod(const std::string& name, const std::string& returnType, Flags flags) :  MethodUnit( name, returnType, flags) { }

    std::string compile( unsigned int level = 0) const {
        std::string result = generateShift(level);
        if(Get_flags() & STATIC) {
            result += "static ";
        } else if(Get_flags() & VIRTUAL) {
            result += "virtual ";
        }

        result += Get_returnType() + " ";
        result += Get_name() + "()";

        if(Get_flags() & CONST ) {
            result += " const";
        }

        result += " {\n";

        for(const auto& b : Get_Body()) {
            result += b->compile(level + 1);
        }

        result += generateShift(level) + "}\n";

        return result;
    }
};

class JavaMethod : public MethodUnit {
public:
    JavaMethod(const std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags) { }

    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift( level );


        if(Get_flags() & PUBLIC ) {
            result += "public ";
        } else if(Get_flags() & PROTECTED ) {
            result += "protected ";
        } else {
            result += "private ";
        }

        if(Get_flags() & STATIC ) {
            result += "static ";
        } else if(!( Get_flags() & VIRTUAL ) ) {
            result += "final ";
        }

        result += Get_returnType() + " ";
        result += Get_name() + "()";

        result += " {\n";

        for(const auto& b : Get_Body() ) {
            result += b->compile(level + 1);
        }

        result += generateShift(level) + "}\n";

        return result;
    }
};

class ChMethod : public MethodUnit
{
public:
    ChMethod(const std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags){ }
    std::string compile(unsigned int level = 0) const {
        std::string result;
        if (Get_flags() & OVERRIDE) {
            result += "override ";
        }
        else if (Get_flags() & SEALED) {
            result += "sealed ";
        }
        if (Get_flags() & STATIC) {
            result += "static ";
        }
        else if (Get_flags() & VIRTUAL) {
            result += "virtual ";
        }
        else if (Get_flags() & ABSTRACT) {
            result += "abstract ";
        }

        result += Get_returnType() + " ";
        result += Get_name() + "()";
        result += " {\n";
        for (const auto& b : Get_Body()) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    }
};

