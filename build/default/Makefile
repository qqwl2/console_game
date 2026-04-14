INCLUDE = -I../../
DEBUG_FLAGS = -Wall -Wextra -Wpedantic -Werror -Wshadow -Wconversion -Wunused-variable -Wduplicated-cond -g
CC = @g++ -c $(INCLUDE) -std=c++23 

OBJ = obj/default.o obj/app.o obj/input.o obj/module_manager.o obj/resources_manager.o \
	obj/robot_manager.o obj/archive.o obj/command_center.o obj/generator.o \
	obj/living_place.o obj/module.o obj/integrator.o obj/keeper.o obj/robot.o \
	obj/event.o obj/factory.o obj/station.o obj/console_interface.o \
	obj/ostream_operators.o obj/utils.o \
	obj/command_factory.o obj/next_day_command.o \
	obj/buy_robot_command.o obj/buy_module_command.o obj/upgrade_module_command.o \
	obj/control_module_command.o obj/synthesis_module_command.o \
	obj/synthesis_robot_command.o obj/analytics_command.o

all: main

main: $(OBJ)
	@g++ $(OBJ) -o main
	@echo "the project is compiled"
debug: CC = @g++ -c $(INCLUDE) -std=c++23 $(DEBUG_FLAGS)
debug: $(OBJ)
	@g++ $(OBJ) -o main_debug
	@echo "the debug project is compiled"
run:
	./main
gdb:
	gdb -q ./main_debug
clean:
	rm obj/*.o main main_debug


obj/default.o:
	$(CC) ../../examples/default.cpp -o obj/default.o
obj/app.o:
	$(CC) ../../src/core/app.cpp -o obj/app.o
obj/input.o:
	$(CC) ../../src/core/input.cpp -o obj/input.o
obj/module_manager.o:
	$(CC) ../../src/entities/managers/module_manager.cpp -o obj/module_manager.o
obj/resources_manager.o:
	$(CC) ../../src/entities/managers/resources_manager.cpp -o obj/resources_manager.o
obj/robot_manager.o:
	$(CC) ../../src/entities/managers/robot_manager.cpp -o obj/robot_manager.o
obj/archive.o:
	$(CC) ../../src/entities/module/module_type/archive.cpp -o obj/archive.o
obj/command_center.o:
	$(CC) ../../src/entities/module/module_type/command_center.cpp -o obj/command_center.o
obj/generator.o:
	$(CC) ../../src/entities/module/module_type/generator.cpp -o obj/generator.o
obj/living_place.o:
	$(CC) ../../src/entities/module/module_type/living_place.cpp -o obj/living_place.o
obj/module.o:
	$(CC) ../../src/entities/module/module.cpp -o obj/module.o
obj/integrator.o:
	$(CC) ../../src/entities/robot/robot_type/integrator.cpp -o obj/integrator.o
obj/keeper.o:
	$(CC) ../../src/entities/robot/robot_type/keeper.cpp -o obj/keeper.o
obj/robot.o:
	$(CC) ../../src/entities/robot/robot.cpp -o obj/robot.o
obj/event.o:
	$(CC) ../../src/entities/event.cpp -o obj/event.o
obj/factory.o:
	$(CC) ../../src/entities/factory.cpp -o obj/factory.o
obj/station.o:
	$(CC) ../../src/entities/station.cpp -o obj/station.o
obj/console_interface.o:
	$(CC) ../../src/graphics/console_interface.cpp -o obj/console_interface.o
obj/ostream_operators.o:
	$(CC) ../../src/utils/ostream_operators.cpp -o obj/ostream_operators.o
obj/utils.o:
	$(CC) ../../src/utils/utils.cpp -o obj/utils.o
obj/command_factory.o:
	$(CC) ../../src/core/commands/command_factory.cpp -o obj/command_factory.o
obj/next_day_command.o:
	$(CC) ../../src/core/commands/next_day_command.cpp -o obj/next_day_command.o
obj/buy_robot_command.o:
	$(CC) ../../src/core/commands/buy_robot_command.cpp -o obj/buy_robot_command.o
obj/buy_module_command.o:
	$(CC) ../../src/core/commands/buy_module_command.cpp -o obj/buy_module_command.o
obj/upgrade_module_command.o:
	$(CC) ../../src/core/commands/upgrade_module_command.cpp -o obj/upgrade_module_command.o
obj/control_module_command.o:
	$(CC) ../../src/core/commands/control_module_command.cpp -o obj/control_module_command.o
obj/synthesis_module_command.o:
	$(CC) ../../src/core/commands/synthesis_module_command.cpp -o obj/synthesis_module_command.o
obj/synthesis_robot_command.o:
	$(CC) ../../src/core/commands/synthesis_robot_command.cpp -o obj/synthesis_robot_command.o
obj/analytics_command.o:
	$(CC) ../../src/core/commands/analytics_command.cpp -o obj/analytics_command.o