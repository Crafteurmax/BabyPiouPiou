#ifndef ENEMY
#define ENEMY

#include "HpLiving.h"

class Enemy : public HpLiving {
public :
	void update(const sf::Time& elapsedTime) override;
private:
	int _waveIndex;
};


#endif //ENEMY