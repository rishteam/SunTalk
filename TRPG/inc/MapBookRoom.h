#pragma once

#include <definition.h>

#include <map.h>
#include <role.h>

void SetupBookRoom(Map &M, Role &role){
    
    M.init();
    Object ObjBookRoom(0, 200, "woodgate");
    M.increase(ObjBookRoom); // 0
    Object ObjBookCase1( 500, 300, "bookcase",true);
    M.increase(ObjBookCase1);
    Object ObjBookCase2(1000, 300, "bookcase", true);
    M.increase(ObjBookCase2);
    Object ObjBookCase3(1500, 300, "bookcase", true);
    M.increase(ObjBookCase3);
    Object ObjBookCase4( 500, -100, "bookcase", true);
    M.increase(ObjBookCase4);
    Object ObjBookCase5(1000, -100, "bookcase", true);
    M.increase(ObjBookCase5);
    Object ObjBookCase6(1500, -100, "bookcase", true);
    M.increase(ObjBookCase6);

    role.setPos(80, 300);
    viewX = 0;
    viewY = 0;

}

void RunBookRoom(sf::RenderWindow &window, Map &M, Role &role){

    switch( M.click(window) ){
        case 1:
            BookCase = true;
            break;
        case 2:
            BookCase = true;
            break;
        case 3:
            BookCase = true;
            break;
        case 4:
            BookCase = true;
            break;
        case 5:
            BookCase = true;
            break;
        case 6:
            BookCase = true;
            break;
        default:
            break;
    }

}