#pragma once
#include <include/entities/station.hpp>
#include <include/graphics/Iinterface.hpp>

class Command {
public:
  virtual ~Command() = default;
  virtual void execute(Station& station, Iinterface& interface) = 0;
};