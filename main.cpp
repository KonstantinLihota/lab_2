#include <QCoreApplication>
#include<classfactory.h>
/*Описание патерна абстрактная фабрика
 * Абстрактная фабрика — это порождающий паттерн проектирования, который позволяет создавать семейства связанных объектов,
 *  не привязываясь к конкретным классам создаваемых объектов.
 * Основная идея Абстрактной фабрики заключается в том,
 * что мы избавляемся от зависимостей при создании конкретных экземпляров классов, которые были в старом варианте кода.
 *
 *Вначале выделим общие интерфейсы для отдельных продуктов, составляющих семейства (языков на которых будет сгенерирован код).
 *Далее создим  абстрактную фабрику  UnitFactory — общий интерфейс, который содержит методы создания всех продуктов семейства  ClassUnit, MethodUnit, PrintOperatorUnit
 *

*/
std::string generateProgram( const std::shared_ptr< UnitFactory >& factory ) {//функция определяющуая логику генерирации кода
                                                                                  //на вход передается умный указатель на генератор юнитов языка
    auto myClass = factory->createClass( "MyClass" ); //определяем имя класса
    myClass->add( factory->createMethod( "testFunc1", "void", MethodUnit::PUBLIC ) ); //добавить метод void
    myClass->add( factory->createMethod( "testFunc2", "void", MethodUnit::STATIC ) );
    myClass->add(
        factory->createMethod(
              "testFunc3",
              "void",
              MethodUnit::VIRTUAL | MethodUnit::CONST | MethodUnit::PUBLIC
        )
    );

    std::shared_ptr< MethodUnit > method = factory->createMethod(
        "testFunc4", "void", MethodUnit::STATIC | MethodUnit::PROTECTED
    );
    method->add( factory->createPrintOperator( R"(Hello, world!\n)" ) );
    myClass->add( method );

    return myClass->compile();
}

void Client(){ //функция генерирующая код на всех заданых языках для проверки корректности работы программы
    std::cout << generateProgram( std::make_shared< C_Factory >() ) << std::endl;
    std::cout << generateProgram( std::make_shared< ChFactory >() ) << std::endl;
    std::cout << generateProgram( std::make_shared< JavaFactory >() ) << std::endl;

}

int main() {
    Client();
    return 0;
}
