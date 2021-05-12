
#define PRINTOPERATORUNIT_H

#pragma once
#include<iostream>
#include<vector>
#include<unit.h>
#include<unit_ch.h>
class PrintOperatorUnit : public Unit
{// класс для вывода в консоль
public:

    explicit PrintOperatorUnit(const std::string &text) : m_text(text)
    { }

private:

    std::string m_text;
protected:
    const std::string& Get_text() const
    {
        return m_text;
    }

};
//Конкретные классы для вывода в консоль с особеностями для каждого яп
class ChPrintOperator : public PrintOperatorUnit {
public:
    ChPrintOperator( const std::string& text) : PrintOperatorUnit(text) { }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "Console.WriteLine(\"" + Get_text() + "\");\n";
    }
};
class JavaPrintOperator : public PrintOperatorUnit {
public:
    JavaPrintOperator( const std::string& text) : PrintOperatorUnit(text) { }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "System.out.print(\"" + Get_text() + "\");\n";
    }
};
class CPrintOperator : public PrintOperatorUnit {
public:
    CPrintOperator( const std::string& text) : PrintOperatorUnit(text) { }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "printf (\"" + Get_text() + "\");\n";
    }
};
