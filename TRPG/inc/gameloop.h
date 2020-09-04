#pragma once

#include <definition.h>
#include <bag.h>

#include <MapStartRoom.h>
#include <MapBookRoom.h>
#include <MapKitchen.h>
#include <MapSlaveRoom.h>
#include <MapAuditorium.h>

void gameloop(sf::RenderWindow &window, Map &M, Role &role){

    ImguiBag();
    switch( NOWPOS ){
        case Locate::STARTROOM :
            if( LocateChange ){
                SetupStartRoom(M, role);
                LocateChange = false;
            }
            RunStartRoom(window, M, role);
            break;
        case Locate::BOOKROOM :
            if (LocateChange){
                SetupBookRoom(M, role);
                LocateChange = false;
            }
            RunBookRoom(window, M, role);
            break;
        case Locate::KITCHEN :
            if (LocateChange){
                SetupKitchen(M, role);
                LocateChange = false;
            }
            RunKitchen(window, M, role);
            break;
        case Locate::SLAVEROOM :
            if (LocateChange){
                SetupSlaveRoom(M, role);
                LocateChange = false;
            }
            RunSlaveRoom(window, M, role);
            break;
        case Locate::AUDITORIUM :
            if (LocateChange){
                SetupAuditorium(M, role);
                LocateChange = false;
            }
            RunAuditorium(window, M, role);
            break;
        default :
            break;
    }

}

