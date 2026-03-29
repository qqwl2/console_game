#pragma once
#include <string>

class Module {
  friend std::ostream& operator<<(std::ostream& os, const Module& module);

private:
  const int id;

protected:
  unsigned int level;
  bool         is_active;
  int          energy;
  int          bits;
  int          upgrade_cost;

public:
  Module(int id);
  virtual void              upgrade() = 0;
  virtual const std::string get_name() const = 0;
  const int                 get_energy() const;
  const int                 get_bits() const;
  const std::string         get_is_active_str() const;
  virtual int               toggle_active();
  virtual const int         get_alive_places() const;
  const int                 get_upgrade_cost() const;
  const int                 get_id() const;
  Module*                   operator+(const Module& _module);
  virtual ~Module() = default;
};