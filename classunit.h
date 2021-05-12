
#pragma once
#include "unit.h"
#include "methodunit.h"

class ClassUnit : public Unit {// Класс обесепчивающий построение тела класса
public:
    enum AccessModifier {// модификаторы для всех яп
        DEFAULT,
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_PRIVATE,
        PROTECTED_INTERNAL
    };
// Метод compile  был вынесен в дочерние классы по причине спецефической работы для каждого языка
    static const std::vector< std::string > ACCESS_MODIFIERS;

    using Fields = std::vector< std::shared_ptr<Unit>>; //вектор состояний

    explicit ClassUnit(const std::string& name) : m_name(name) {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    //Убран flag тк добавлена вспомогательная функция Get_flags, которая дает возможность получить флаг
    void add( const std::shared_ptr<Unit>& unit) {
        int accessModifier = PRIVATE;
        if(unit->Get_flags() & MethodUnit::PUBLIC) {
            accessModifier = PUBLIC;
        } else if(unit->Get_flags() & MethodUnit::PROTECTED) {
            accessModifier = PROTECTED;
        }

        m_fields[accessModifier].push_back(unit);
    }

protected:
    const std::string& Get_name() const { // функция для получения m_name
        return m_name;
    }

    const Fields& Get_felds(unsigned int accessGroup) const {// функция для получения состояния

        return m_fields[accessGroup];
    }

private:
    std::string m_name;
    std::vector<Fields> m_fields;

};


//классы определяющий логику построения тела класса MyClass для каждого яп с измененой функций compile
class C_Class : public ClassUnit {
public:
    C_Class(const std::string& name) : ClassUnit(name) { }

    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level) + "class " + Get_name() + " {\n";
        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            if(Get_felds(i).empty()) {
                continue;
            }

            result += ACCESS_MODIFIERS[i] + ":\n";
            for(const auto& f : Get_felds(i)) {
                result += f->compile(level + 1);
            }

            result += "\n";
        }
        result += generateShift(level) + "};\n";

        return result;
    }
};

class JavaClass : public ClassUnit {
public:
    JavaClass(const std::string& name) : ClassUnit(name) { }

    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift( level ) + "class " + Get_name() + " {\n";
        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            for(const auto& f : Get_felds(i)) {
                result += f->compile(level + 1);
                result += "\n";
            }
        }
        result += generateShift(level) + "}\n";

        return result;
    }
};


class ChClass : public ClassUnit
{
public:
    ChClass(const std::string& name) : ClassUnit(name) { }
    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level) + "class " + Get_name() + " {\n";
        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            for(const auto& f : Get_felds(i)) {
                result += f->compile(level + 1);
                result += "\n";
            }
        }
        result += generateShift(level) + "}\n";

        return result;
    }
};
