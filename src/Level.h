#ifndef LEVEL
#define LEVEL

#include <string>
#include <pugixml.hpp>

class Level {
public:
	explicit Level(const std::string& label);
private:
	std::string _label;
};

#endif // LEVEL