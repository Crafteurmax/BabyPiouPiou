#ifndef ENEMY
#define ENEMY

#include "SpellCard.h"

#include "HpLiving.h"
#include "pugixml.hpp"

class Enemy : public HpLiving {
public :
	Enemy(const Enemy& other) = default;
	Enemy(const pugi::xml_node& node);
	Enemy(const Enemy& prefab, const std::string& label);

	inline std::unique_ptr<Enemy> clone() const { return std::make_unique<Enemy>(*this); }

	void update(const sf::Time& elapsedTime) override;
	void setupInstance(const std::string& label, const sf::Vector2f& position);



private:
	int _waveIndex;
	std::vector<SpellCard> _spellcards;
};


#endif //ENEMY