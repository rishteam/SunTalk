#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

#include <definition.h>

#include <MapStartRoom.h>
#include <MapBookRoom.h>
#include <MapKitchen.h>
#include <MapSlaveRoom.h>
#include <MapAuditorium.h>

void ImguiLog(){

    ImGui::Begin("Log");
    switch (NOWPOS){
        case Locate::STARTROOM:
            if (BookRoomdata){
                if (ImGui::TreeNode("BookRoom")){
                    ImGui::Text("It’s not locked, it should be easy to open.");
                    if (ImGui::Button("Enter BookRoom"))
                    {
                        NOWPOS = Locate::BOOKROOM;
                        LocateChange = true;
                    }
                    ImGui::TreePop();
                }
            }
            if (Kitchendata){
                if (ImGui::TreeNode("Kitchen")){
                    ImGui::Text("The door is all white, kitchen style sliding door without door handle");
                    if (ImGui::Button("Enter Kitchen"))
                    {
                        NOWPOS = Locate::KITCHEN;
                        LocateChange = true;
                    }
                    ImGui::TreePop();
                }
            }
            if (SlaveRoomdata){
                if (ImGui::TreeNode("SlaveRoom")){
                    ImGui::Text("Although the door is locked, it is very fragile.");
                    if (ImGui::Button("Enter SlaveRoom"))
                    {
                        NOWPOS = Locate::SLAVEROOM;
                        LocateChange = true;
                    }
                    ImGui::TreePop();
                }
            }
            if (Auditoriumdata){
                if (ImGui::TreeNode("Auditorium")){
                    ImGui::Text("Huge heavy iron door with small windows");
                    if (ImGui::Button("Enter Auditorium"))
                    {
                        NOWPOS = Locate::AUDITORIUM;
                        LocateChange = true;
                    }
                    ImGui::TreePop();
                }
            }
            break;
        case Locate::BOOKROOM:
            if (ImGui::Button("GoBack StartRoom")){
                NOWPOS = Locate::STARTROOM;
                LocateChange = true;
            }
            break;
        case Locate::KITCHEN:
            if (ImGui::Button("GoBack StartRoom")){
                NOWPOS = Locate::STARTROOM;
                LocateChange = true;
            }
            break;
        case Locate::SLAVEROOM:
            if (ImGui::Button("GoBack StartRoom")){
                NOWPOS = Locate::STARTROOM;
                LocateChange = true;
            }
            break;
        case Locate::AUDITORIUM:
            if (ImGui::Button("GoBack StartRoom")){
                NOWPOS = Locate::STARTROOM;
                LocateChange = true;
            }
            break;
        default:
            break;
    }
    ImGui::End();

}

