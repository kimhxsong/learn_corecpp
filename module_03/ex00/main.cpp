#include <iostream>

#include "ClapTrap.h"

int main(void) {
  ClapTrap clap("Base");

  clap.attack("target_1");
  clap.takeDamage(3);
  clap.beRepaired(3);
  return 0;
}