#pragma once
#include <list>
#include <string>

class Observer;

class Subject {
private:
  std::list<Observer*> observers;
  std::string          event;

public:
  void attach(Observer& observer);
  void detach(Observer& observer);
  void notify();
  void set_event(const std::string& message);
};

class Observer {
public:
  Observer(Subject& subject);
  virtual void update(const std::string& message) = 0;
};