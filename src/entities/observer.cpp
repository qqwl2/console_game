#include <algorithm>
#include <include/entities/observer.hpp>

Observer::Observer(Subject& subject) {
  subject.attach(*this);
}

void
Subject::attach(Observer& observer) {
  observers.push_back(&observer);
}
void
Subject::detach(Observer& observer) {
  observers.remove(&observer);
}
void
Subject::notify() {
  std::ranges::for_each(observers, [this](auto& observer) { observer->update(event); });
}
void
Subject::set_event(const std::string& message) {
  event = message;
}