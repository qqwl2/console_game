#include <include/entities/event.hpp>

void
Event::add_events(const std::string event) {
  events.push_back(event);
}
void
Event::remove_events() {
  while (events.size() > 5) {
    events.erase(events.begin(), events.end() - 5);
  }
  events.shrink_to_fit();
}