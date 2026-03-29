INCLUDE = -I../../
CCI = g++ -c $(INCLUDE) 

all: main

main: obj/default.o obj/app.o obj/input.o obj/module_manager.o obj/resources_manager.o obj/robot_manager.o obj/archive.o obj/command_center.o obj/generator.o obj/living_place.o obj/module.o obj/integrator.o obj/keeper.o obj/robot.o obj/event.o obj/factory.o obj/station.o obj/console_interface.o obj/ostream_operators.o obj/utils.o
	g++ obj/default.o obj/app.o obj/input.o obj/module_manager.o obj/resources_manager.o obj/robot_manager.o obj/archive.o obj/command_center.o obj/generator.o obj/living_place.o obj/module.o obj/integrator.o obj/keeper.o obj/robot.o obj/event.o obj/factory.o obj/station.o obj/console_interface.o obj/ostream_operators.o obj/utils.o -o main
	@echo "the project is compiled"

obj/default.o:
	$(CCI) ../../examples/default.cpp -o obj/default.o
obj/app.o:
	$(CCI) ../../src/core/app.cpp -o obj/app.o
obj/input.o:
	$(CCI) ../../src/core/input.cpp -o obj/input.o
obj/module_manager.o:
	$(CCI) ../../src/entities/managers/module_manager.cpp -o obj/module_manager.o
obj/resources_manager.o:
	$(CCI) ../../src/entities/managers/resources_manager.cpp -o obj/resources_manager.o
obj/robot_manager.o:
	$(CCI) ../../src/entities/managers/robot_manager.cpp -o obj/robot_manager.o
obj/archive.o:
	$(CCI) ../../src/entities/module/module_type/archive.cpp -o obj/archive.o
obj/command_center.o:
	$(CCI) ../../src/entities/module/module_type/command_center.cpp -o obj/command_center.o
obj/generator.o:
	$(CCI) ../../src/entities/module/module_type/generator.cpp -o obj/generator.o
obj/living_place.o:
	$(CCI) ../../src/entities/module/module_type/living_place.cpp -o obj/living_place.o
obj/module.o:
	$(CCI) ../../src/entities/module/module.cpp -o obj/module.o
obj/integrator.o:
	$(CCI) ../../src/entities/robot/robot_type/integrator.cpp -o obj/integrator.o
obj/keeper.o:
	$(CCI) ../../src/entities/robot/robot_type/keeper.cpp -o obj/keeper.o
obj/robot.o:
	$(CCI) ../../src/entities/robot/robot.cpp -o obj/robot.o
obj/event.o:
	$(CCI) ../../src/entities/event.cpp -o obj/event.o
obj/factory.o:
	$(CCI) ../../src/entities/factory.cpp -o obj/factory.o
obj/station.o:
	$(CCI) ../../src/entities/station.cpp -o obj/station.o
obj/console_interface.o:
	$(CCI) ../../src/graphics/console_interface.cpp -o obj/console_interface.o
obj/ostream_operators.o:
	$(CCI) ../../src/utils/ostream_operators.cpp -o obj/ostream_operators.o
obj/utils.o:
	$(CCI) ../../src/utils/utils.cpp -o obj/utils.o

run:
	./main

clean:
	rm obj/*.o