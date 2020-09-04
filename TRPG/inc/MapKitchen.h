#pragma once

#include <definition.h>

#include <map.h>
#include <role.h>

void SetupKitchen(Map &M, Role &role){

    M.init();
    Object ObjKitchen(0, 200, "slidingdoor");
    M.increase(ObjKitchen);
    role.setPos(80, 300);

}

void RunKitchen(sf::RenderWindow &window, Map &M, Role &role){
}