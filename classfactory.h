
#define CLASSFACTORY_H

#pragma once
#include<unit.h>
#include<methodunit.h>
#include<unitfactory.h>
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = {"default",
                                                                "public",
                                                                "protected",
                                                                "private",
                                                                "internal",
                                                                "protected_private",
                                                                "protected_internal"};


//Создание конкретных фабрик для каждого языка
class C_Factory : public UnitFactory //с++
{
public:
    std::unique_ptr< ClassUnit > createClass(const std::string& name) {
        return std::unique_ptr< ClassUnit >(new C_Class(name));
    }

    std::unique_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) {
        return std::unique_ptr<MethodUnit>(new CMethod(name, returnType, flags));
    }

    std::unique_ptr< PrintOperatorUnit > createPrintOperator(const std::string& text) {
        return std::unique_ptr< PrintOperatorUnit >(new CPrintOperator(text));
    }
};

class JavaFactory : public UnitFactory {//Java
public:
    std::unique_ptr<ClassUnit> createClass(const std::string& name) {
        return std::unique_ptr<ClassUnit>(new JavaClass(name));
    }

    std::unique_ptr<MethodUnit> createMethod(
        const std::string& name,
        const std::string& returnType,
        Unit::Flags flags
    ) {
        return std::unique_ptr<MethodUnit>(new JavaMethod(name, returnType, flags));
    }

    std::unique_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) {
        return std::unique_ptr<PrintOperatorUnit>(new JavaPrintOperator(text));
    }
};

class ChFactory : public UnitFactory//C#
{
public:
    std::unique_ptr< ClassUnit > createClass(const std::string& name) {
        return std::unique_ptr< ClassUnit >(new ChClass(name));
    }

    std::unique_ptr< MethodUnit > createMethod(
        const std::string& name,
        const std::string& returnType,
        Unit::Flags flags
    ) {
        return std::unique_ptr< MethodUnit >(new ChMethod(name, returnType, flags));
    }

    std::unique_ptr< PrintOperatorUnit > createPrintOperator(const std::string& text) {
        return std::unique_ptr< PrintOperatorUnit >(new ChPrintOperator(text));
    }
};
