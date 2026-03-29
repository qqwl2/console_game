#pragma once
#include <iostream>

class Station;
class Robot;
class Module;
class Robot_manager;
class Resources_manager;
class Module_manager;
class Event;

std::ostream&
operator<<(std::ostream& os, const Station& station);
std::ostream&
operator<<(std::ostream& os, const Robot& robot);
std::ostream&
operator<<(std::ostream& os, const Module& module);
std::ostream&
operator<<(std::ostream& os, const Robot_manager& robot_manager);
std::ostream&
operator<<(std::ostream& os, const Resources_manager& resources_manager);
std::ostream&
operator<<(std::ostream& os, const Module_manager& module_manager);
std::ostream&
operator<<(std::ostream& os, const Event& event);