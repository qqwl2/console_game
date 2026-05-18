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
  Module(int _id);
  virtual void        upgrade() = 0;
  virtual std::string get_name() const = 0;
  virtual void        storm_reaction() = 0;
  int                 get_energy() const;
  int                 get_bits() const;
  std::string         get_is_active_str() const;
  virtual int         toggle_active();
  virtual int         get_alive_places() const;
  int                 get_upgrade_cost() const;
  int                 get_id() const;
  int                 get_level() const;
  Module*             operator+(const Module& _module);
  virtual ~Module() = default;
};