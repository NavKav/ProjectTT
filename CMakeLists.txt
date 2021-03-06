cmake_minimum_required(VERSION 3.9)
project(ProjectTT CXX) #nom de projet et langage utilisé

set(CMAKE_CXX_STANDARD 14) #version du langage -lmingw32 -lSDL2main -lSDL2

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-dev") #Affiche TOUS les warnings en mode debug
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/SDL2/cmake") #chemin pour accéder au fichier cmake
#qui vont trouver les différents fichiers nécessaire pour utiliser SDL2

set(SDL2_IMAGE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/include") #chemin spécifiant l'endroit où se situe vos .h pour
#SDL2_Image
set(SDL2_IMAGE_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/lib/libSDL2_image.dll.a") #chemin spécifiant l'endroit où se situe vos
#bibliothèques pour SDL2_Image

set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SDL2/include")
set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/SDL2/lib/libSDL2.dll.a")
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)

add_executable(ProjectTT src/main.cpp src/Displayer/Window.cpp src/GameEngine/Hitbox.cpp include/GameEngine/Hitbox.h include/Displayer/Window.h src/GameEngine/PhysicRuler.cpp include/GameEngine/PhysicRuler.h src/GameEngine/Ball.cpp include/GameEngine/Ball.h src/GameEngine/TrajectoryFunction.cpp include/GameEngine/TrajectoryFunction.h include/GameEngine/HitboxEffect.h src/GameEngine/ChangeTrajectoryEffect.cpp include/GameEngine/ChangeTrajectoryEffect.h include/GameEngine/GameEngine.h src/DisplayerConnection.cpp include/DisplayerConnection.h src/DisplayerSource.cpp include/DisplayerSource.h src/GameEngine/BounceEffect.cpp include/GameEngine/BounceEffect.h src/PlayerSource.cpp include/PlayerSource.h src/Player/Player.cpp include/Player/Player.h)

include_directories(${PROJECT_SOURCE_DIR}/include ${SDL2_IMAGE_INCLUDE_DIR}) #inclusion des dossier nécessaire pour le
#développement avec SDL2
target_link_libraries(ProjectTT ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ) #inclusion des bibliothèques nécessaire pour
#le développement avec SDL2