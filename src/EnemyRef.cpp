#include "EnemyRef.h"

#include <iostream>

EnemyRef::EnemyRef(const std::weak_ptr<Enemy>& prefab, const sf::Vector2f& position, const std::string& label) : _enemyPrefab(prefab), _position(position), _label(label) {};

std::unique_ptr<Enemy> EnemyRef::spawn() const {
	if (const auto enemyPref = _enemyPrefab.lock()) {
		auto enemy = enemyPref->clone();
		enemy->setupInstance(_label, _position);
		
		return std::move(enemy);
	}
	else {
		std::cerr << "Trying to spawn an unloaded prefab, please check XML DATA : " << _label << std::endl; //LES FICHIERS XML SONT CORROMPUS, FERMER LE JEU
		exit(-1);
	}
}