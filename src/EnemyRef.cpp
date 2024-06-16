#include "EnemyRef.h"

#include <iostream>

EnemyRef::EnemyRef(const std::weak_ptr<Enemy>& prefab, const sf::Vector2f& position, const std::string& label) : _enemyPrefab(prefab), _position(position), _label(label) {};

std::unique_ptr<Enemy> EnemyRef::spawn() const {
	std::cout << "enemy->getLabel()" << std::endl;
	if (const auto enemyPref = _enemyPrefab.lock()) {
		//std::unique_ptr<Enemy> enemy; //TODO SUPPRIMER ET DECOMMENTER LIGNE CI DESSOUS + GERER LA COPIE
		auto enemy = enemyPref->clone();
		std::cout << enemy->getLabel() << std::endl;
		enemy->setupInstance(_label, _position);
		
		return std::move(enemy);
	}
	else {
		std::cerr << "Trying to spawn an unloaded prefab : " << _label << std::endl; //EXCEPTION, NORMALEMENT ETAT IMPOSSIBLE
		exit(-1);
		//return std::nullopt;
	}
}