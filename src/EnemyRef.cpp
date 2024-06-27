#include "EnemyRef.h"

#include <iostream>

EnemyRef::EnemyRef(const Enemy* & prefab, const sf::Vector2f& position, const std::string& label) : _enemyPrefab(prefab), _position(position), _label(label) {};

std::unique_ptr<Enemy> EnemyRef::spawn() const {
	//Pas de multithreading donc ok
	if (_enemyPrefab != nullptr) {
		auto enemy = _enemyPrefab->clone();
		enemy->setupInstance(_label, _position);
		
		return std::move(enemy);
	}
	else {
		std::cerr << "Trying to spawn an unloaded prefab, please check XML DATA : " << _label << std::endl; //LES FICHIERS XML SONT CORROMPUS, FERMER LE JEU
		exit(-1);
	}
}