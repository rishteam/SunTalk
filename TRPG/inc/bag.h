#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

#include <definition.h>

#include <MapStartRoom.h>
#include <MapBookRoom.h>
#include <MapKitchen.h>
#include <MapSlaveRoom.h>
#include <MapAuditorium.h>

void ImguiBag(){

    ImGui::Begin("Bag");
    if (ImGui::TreeNode("Article")){
        if( Lampdata ){
            if( ImGui::TreeNode("Lamp") ){
                ImGui::Text("Just a Lamp");
            }
        }
        if (Soupdata){
            if (ImGui::TreeNode("Soup")){
                ImGui::TreePop();
            }
        }
        if (ReadPaperone){
            if (ImGui::TreeNode("ParperOne")){
                ImGui::Text("BookRoom - Kitchen - SoupRoom - SlaveRoom - Auditorium\n");
                ImGui::TreePop();
            }
        }
        if (ReadPapertwo){
            if (ImGui::TreeNode("ParperTwo")){
                ImGui::Text("if you want to back, drink this poisonous soup in an hour\n");
                ImGui::TreePop();
            }
        }
        ImGui::TreePop();
    }
    if (ImGui::TreeNode("MapData")){

        switch (NOWPOS){
            case Locate::STARTROOM:
                if (BookRoomdata){
                    if (ImGui::TreeNode("BookRoom")){
                        ImGui::Text("It’s not locked, it should be easy to open.");
                        if (ImGui::Button("Enter BookRoom")){
                            NOWPOS = Locate::BOOKROOM;
                            LocateChange = true;
                        }
                        ImGui::TreePop();
                    }
                }
                if (Kitchendata){
                    if (ImGui::TreeNode("Kitchen")){
                        ImGui::Text("The door is all white, kitchen style sliding door without door handle");
                        if (ImGui::Button("Enter Kitchen")){
                            NOWPOS = Locate::KITCHEN;
                            LocateChange = true;
                        }
                        ImGui::TreePop();
                    }
                }
                if (SlaveRoomdata){
                    if (ImGui::TreeNode("SlaveRoom")){
                        ImGui::Text("Although the door is locked, it is very fragile.");
                        if (ImGui::Button("Enter SlaveRoom")){
                            NOWPOS = Locate::SLAVEROOM;
                            LocateChange = true;
                        }
                        ImGui::TreePop();
                    }
                }
                if (Auditoriumdata){
                    if (ImGui::TreeNode("Auditorium")){
                        ImGui::Text("Huge heavy iron door with small windows");
                        if (ImGui::Button("Enter Auditorium")){
                            NOWPOS = Locate::AUDITORIUM;
                            LocateChange = true;
                        }
                        ImGui::TreePop();
                    }
                }
                break;
            case Locate::BOOKROOM:
                if( ImGui::Button("GoBack StartRoom") ){
                    NOWPOS = Locate::STARTROOM;
                    LocateChange = true;
                }
                break;
            case Locate::KITCHEN:
                if( ImGui::Button("GoBack StartRoom") ){
                    NOWPOS = Locate::STARTROOM;
                    LocateChange = true;
                }
                break;
            case Locate::SLAVEROOM:
                if( ImGui::Button("GoBack StartRoom") ){
                    NOWPOS = Locate::STARTROOM;
                    LocateChange = true;
                }
                break;
            case Locate::AUDITORIUM:
                if( ImGui::Button("GoBack StartRoom") ){
                    NOWPOS = Locate::STARTROOM;
                    LocateChange = true;
                }
                break;
            default:
                break;
        }

        ImGui::TreePop();
    }

    ImGui::End();
}
