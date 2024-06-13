#ifndef PLAYER
#define PLAYER

#include "HpLiving.h"

class Player : public HpLiving {
public:
	void update() override;
};


#endif //PLAYER
