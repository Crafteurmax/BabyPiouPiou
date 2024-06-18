#include "BulletRef.h"

BulletRef::BulletRef(const std::weak_ptr<Projectile>& prefab, const sf::Vector2f& position, const std::string& label)
{
}

std::unique_ptr<Projectile> BulletRef::spawn(sf::Vector2f origin) const
{
	if (const auto projPrefab = _BulletPrefab.lock()) {
		auto proj = projPrefab->clone();
		proj->setupInstance(_position);

		return std::move(proj);
		std::cout << "haaaaaaaaaaaaaaaaaaa" << std::endl;
	}
	else std::cout << "?????????????" << std::endl;
}
