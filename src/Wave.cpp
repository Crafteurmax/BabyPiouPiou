#include "Wave.h"

#include <iostream>

Wave::Wave(const pugi::xml_node& node, const std::vector<std::shared_ptr<Enemy>>& enemiesObjects) {
	for (const auto& child : node.children()) {
		const auto label = child.attribute("label").as_string();
		const auto pos = sf::Vector2f(child.attribute("pos_x").as_float(), child.attribute("pos_y").as_float());
		const auto ref = child.attribute("ref").as_string();

		std::cout << "test1" << std::endl;
		for (const auto& enemy : enemiesObjects) {
			std::cout << std::string(ref) << " : " << enemy->getLabel() << std::endl;
			if (std::string(ref) == enemy->getLabel()) {
				const std::weak_ptr<Enemy> enemyPref = enemy;
				_enemiesRef.emplace_back(enemyPref, pos, label);
				break;
			}
		}
	}
}

void Wave::spawnEnemies(std::vector<std::unique_ptr<Enemy>>& enemies) const {
	std::cout << "spawnEnemies" << std::endl;
	for (const auto& enemyRef : _enemiesRef) {
		/*const auto& enemy = enemyRef.spawn();*/
		//if (enemy.has_value()) {
		//	enemies.push_back(std::move(enemy.value()));
		//}
		std::cout << "spawnEnemy" << std::endl;
		enemies.push_back(enemyRef.spawn());
		
	}
}