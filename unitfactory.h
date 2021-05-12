#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#pragma once
#include<unit.h>
#include<unit_ch.h>
#include<iostream>
#include<printoperatorunit.h>
#include<vector>
#include<classunit.h>
//Класс абстрактная фабрика в который вынесены методы создания всех классов
class UnitFactory
{
public:
    virtual ~UnitFactory() = default;

    virtual std::unique_ptr< ClassUnit> createClass(const std::string& name) = 0;

    virtual std::unique_ptr< MethodUnit > createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;

    virtual std::unique_ptr< PrintOperatorUnit > createPrintOperator(const std::string& text) = 0;
};

#endif // UNITFACTORY_H
