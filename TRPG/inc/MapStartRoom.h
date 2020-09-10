#pragma once

#include <definition.h>

#include <map.h>
#include <role.h>

void SetupStartRoom(Map &M, Role &role){

    M.init();
    Object ObjLamp(540,0,"lamp", true);
    M.increase(ObjLamp); // 0
    Object ObjTable(490,300,"table");
    M.increase(ObjTable); // 1
    Object ObjSoup(580,410,"soup", true);
    M.increase(ObjSoup); // 2
    Object Objpaper(670,430,"paper", true);
    M.increase(Objpaper); // 3
    Object Objparper2(540,430,"paper", true);
    M.increase(Objparper2); // 4

    Object ObjBookRoom(-1500, 200, "woodgate", true);
    M.increase(ObjBookRoom); // 5
    Object ObjKitchen(-500, 200, "slidingdoor", true);
    M.increase(ObjKitchen); // 6
    Object ObjSlaveRoom(1500, 200, "irongate", true);
    M.increase(ObjSlaveRoom); // 7
    Object ObjAuditorium(2500, 100,"bigirongate", true);
    M.increase(ObjAuditorium); // 8

    role.setPos(740, 300);
    viewX = 0;
    viewY = 0;

}

void RunStartRoom(sf::RenderWindow &window, Map &M, Role &role){

    switch( M.click(window) ) {
        case 0:
            Lampdata = true;
            break;
        case 2:
            Soupdata = true;
            break;
        case 3:
            ReadPaperone = true;
            break;
        case 4:
            ReadPapertwo = true;
            break;
        case 5:
            BookRoomdata = true;
            break;
        case 6:
            Kitchendata = true;
            break;
        case 7:
            SlaveRoomdata = true;
            break;
        case 8:
            Auditoriumdata = true;
            break;
        default:
            break;
    }
    
}