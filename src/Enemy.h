#ifndef ENEMY
#define ENEMY

#include "HpLiving.h"

class Enemy : public HpLiving {
public :
	void update() override;
private:
	int _waveIndex;
};


#endif //ENEMY