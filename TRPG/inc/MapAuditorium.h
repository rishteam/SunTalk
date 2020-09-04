#pragma once

#include <definition.h>

#include <map.h>
#include <role.h>

void SetupAuditorium(Map &M, Role &role){

    M.init();
    Object ObjAuditorium(0, 100, "bigirongate");
    M.increase(ObjAuditorium);
    role.setPos(80, 300);

}

void RunAuditorium(sf::RenderWindow &window, Map &M, Role &role){

}