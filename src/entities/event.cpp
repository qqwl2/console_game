#include <format>
#include <include/entities/event.hpp>

void
Event::add_events(const std::string event, int day) {
  events.push_back(std::format("День {}: {}", day, event));
}
void
Event::remove_events() {
  while (events.size() > 5) {
    events.erase(events.begin(), events.end() - 5);
  }
}