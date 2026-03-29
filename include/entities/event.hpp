#pragma once
#include <string>
#include <vector>

class Event {
  friend std::ostream& operator<<(std::ostream& os, const Event& event);

private:
  std::vector<std::string> events;

public:
  void add_events(const std::string event);
  void remove_events();
};