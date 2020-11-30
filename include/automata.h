#pragma once

#include <cstdint>
#include <string>
#include <vector>

enum class STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
struct PRODUCT {
	std::string name;
	std::uint32_t price;
};

class Automata {
private:
	STATES state;

	uint32_t bank; // automata's money
	uint32_t cash; // user's contrib
	uint32_t order; // user's choice

	// One common menu for all the automates
	static std::vector<PRODUCT> menu;
public:
	Automata();
	bool on();
	bool off();

	bool coin(uint32_t cash);
	bool choice(uint32_t number);
	bool check();

	uint32_t cook();
	uint32_t cancel();

	static std::string getMenu();
};
