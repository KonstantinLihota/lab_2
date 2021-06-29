#ifndef UNIT_H
#define UNIT_H

#pragma once
#include<iostream>
#include <memory>

// Базовый абстрактный класс определяющий общую логику
class Unit {
public:
    using Flags = unsigned int; //модификатор
public:
    virtual ~Unit() = default;
    virtual void add(const std::shared_ptr< Unit > &)//добавить языковую конструкцию
    {
        throw std::runtime_error("Not supported");
    }
    virtual std::string compile(unsigned int level = 0) const = 0;//получить код конструкции
    virtual Flags Get_flags() const { return 0; }
protected:
    virtual std::string generateShift(unsigned int level) const //функция отвечающая за отступы при генерации
    { static const auto DEFAULT_SHIFT = " ";
        std::string result; for (unsigned int i = 0; i < level; ++i)
        {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};


#endif // UNIT_H
