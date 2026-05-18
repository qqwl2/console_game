#pragma once
#include <string>
#include <deque>

class Event {
  friend std::ostream& operator<<(std::ostream& os, const Event& event);

private:
  std::deque<std::string> events;

public:
  void add_events(const std::string event, int day);
  void remove_events();
};