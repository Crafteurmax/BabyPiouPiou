#ifndef WAVE
#define WAVE

class Wave {
public:
	Wave(const pugi::xml_node& node);

private:
	std::vector<EnemyRef> _enemiesRef;
};


#endif