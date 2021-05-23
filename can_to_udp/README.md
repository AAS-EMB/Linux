# CAN TO UDP

Ретранслятор на несколько интерфейсов CAN-UDP на базе ОС Linux. В качестве API работы с CAN используется SocketCAN.
Для использования неблокирующих сокетов используется метод poll(). Язык программирования - С.

Repeater for several CAN-UDP interfaces based on Linux OS. SocketCAN is used as an API for working with CAN.
The poll () method is used to use non-blocking sockets. The programming language is C.

# HOW IT WORKS

* В директории проекта выполнить make;
* Запустить исполняемый файл в качестве демона;
* При помощи утилиты can-utils можно работать с CAN шиной;
* При помощи утилиты netcat можно работать с UDP.
----------------------------------------------------------------------------------------------
* Run make in the project directory;
* Run the executable file as a daemon;
* Using the can-utils utility, you can work with the CAN bus;
* Using the netcat utility, you can work with UDP.

# LICENSE

Все исходные материалы для проекта распространяются по лицензии MIT. Вы можете использовать проект в любом виде,
в том числе и для коммерческой деятельности, но стоит помнить, что автор проекта не дает никаких гарантий на
работоспособность устройства или частей проекта, а так же не несет никакой ответственности по искам или
за нанесенный ущерб.

All source materials for the project are distributed under the MIT license. You can use the project in any form,
including for commercial activities, but it is worth remembering that the author of the project does not give any guarantees for
the operation of the device or parts of the project, and does not bear any liability for claims or
for the damage done.
