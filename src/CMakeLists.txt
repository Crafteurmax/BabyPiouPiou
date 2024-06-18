
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES}  "myMain.cpp"   "myMain.h" "Game.h" "Game.cpp" "DrawableObject.h" "DrawableObject.cpp" "HpLiving.cpp" "HpLiving.h" "Player.cpp" "Enemy.h" "Enemy.cpp" "SpellCard.h" "SpellCard.cpp" "Projectile.h" "Level.h" "Level.cpp"   "Tank.h" "Tank.cpp"   "Drunk.h"   "Drunk.cpp" "EnemyRef.h" "EnemyRef.cpp" "Background.h" "CoolMath.h" "Speeder.h" "Speeder.cpp" "Boss.cpp" "Boss.h" "TextureList.h" "TextureList.cpp")
target_include_directories(src PUBLIC ./)
target_link_libraries(src PUBLIC pugixml sfml-graphics ImGui-SFML::ImGui-SFML)
