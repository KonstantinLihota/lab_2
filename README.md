
# Отчет
### Постановка задачи и описание предложеного решения 
Модифицировать базовый код так, чтобы сделать его расширяемым, и обеспечить генерацию программ и на других языках программирования(Java, C# и C++)
Для этого воспользуемся паттерном Абстрактная фабрика. Описание паттерна дано в комментариях к функции main.

 В качестве основных достоинств паттерна можно выделить 
* Скрывает сам процесс порождения объектов, а также делает систему независимой от типов создаваемых объектов, специфичных для различных семейств или групп (пользователи оперируют этими объектами через соответствующие абстрактные интерфейсы).
* Позволяет быстро настраивать систему на нужное семейство создаваемых объектов.

В качестве основного недостатка можно выделить 
* Трудно добавлять новые типы создаваемых продуктов или заменять существующие, так как интерфейс базового класса абстрактной фабрики фиксирован.

Архитектура программы выглядит следующим образом 

![image](https://user-images.githubusercontent.com/64350198/129145745-5993415b-7b2a-4e19-8b8f-8141c17a8d47.png)

### Код программы предоставлен в репозитории

### Тестрирование 
Программа генерируюет код на 3 разных языках, по шаблону, который требовался в задаче.

![image](https://user-images.githubusercontent.com/64350198/123799815-ca345c80-d912-11eb-861e-a0f2497d2089.png)

![image](https://user-images.githubusercontent.com/64350198/123799841-d28c9780-d912-11eb-9ea9-e5e445b8b1f0.png)

# Пояснения к виду репозитория
Я ошибочно создал ветку develop, так что ее нельзя было обьеденить с мастер(или я не смог найти как это сделать). Я переименовал ее и правильно создал dev на которой будет вестись разработка. master_ новая ветка релиза.
