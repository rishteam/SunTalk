#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

#include <definition.h>

#include <MapStartRoom.h>
#include <MapBookRoom.h>
#include <MapKitchen.h>
#include <MapSlaveRoom.h>
#include <MapAuditorium.h>

void ImguiBag(Role &role){

    ImGui::Begin("Bag");
    if( Lampdata ){
        if( ImGui::TreeNode("Lamp") ){
            ImGui::Text("Just a Lamp");
            ImGui::TreePop();
        }
    }
    if( Soupdata ){
        if (ImGui::TreeNode("Soup")){
            ImGui::Text("Just a Soup");
            ImGui::TreePop();
        }
    }
    if( ReadPaperone ){
        if (ImGui::TreeNode("ParperOne")){
            ImGui::Text("BookRoom - Kitchen - SoupRoom - SlaveRoom - Auditorium\n");
            ImGui::TreePop();
        }
    }
    if( ReadPapertwo ){
        if (ImGui::TreeNode("ParperTwo")){
            ImGui::Text("if you want to back, drink this poisonous soup in an hour\n");
            ImGui::TreePop();
        }
    }
    if( BookCase && !DreamBook ){
        if ( ImGui::TreeNode("BookCase") ){
            if (ImGui::Button("Observed")){
                DreamBook = role.ObservedtoObj();
                BookCase = false;
            }
            ImGui::TreePop();
        }
    }
    if( DreamBook ){
        if( ImGui::TreeNode("DreamBook") ){
            ImGui::Text("StartRoom :");
            ImGui::Text("can't leave if I don't finish drinking the soup");
            ImGui::Text("BookRoom :");
            ImGui::Text("books are very important so you can't take them oout, but the candles are okay");
            ImGui::Text("Kitchen :");
            ImGui::Text("there are a lot of seasonings and utensils, and some prepared soup is in the pot.");
            ImGui::Text("SlaveRoom :");
            ImGui::Text("a good girl is waiting for you she hase good thins in her hands");
            ImGui::Text("Auditorium");
            ImGui::Text("the god is sleeping here, with information about poison, the guard will not disappear without eating living things.");
            ImGui::Text("The most important thing");
            ImGui::Text("please drink with the consciousness of death");
            ImGui::TreePop();
        }
    }
    if( DeadBody ){
        if( ImGui::Button("Reset BodyPaper") ){
            BodyPaperObserved = false;
            BodyPaperSuccesObs = false;
        }
        if( ImGui::TreeNode("DeadBody") ){

            if (BodyPaperObserved){
                if ( BodyPaperSuccesObs ){
                    if( ImGui::TreeNode("BodyPaper") ){
                        ImGui::Text("She is your faithful servant without a name.\n");
                        ImGui::Text("As long as you command, you will absolutely obey even if you don't want to.\n");
                        ImGui::Text("Although he doesn't like talking, he is a clingy boy\n");
                        ImGui::Text("So please cherish and take care of her\n");
                        ImGui::TreePop();
                    }
                }
                else{
                    ImGui::Text("Nothing here\n");
                }
            }
            else{
                if( ImGui::Button("Observed") ){
                    BodyPaperSuccesObs = role.ObservedtoObj();
                    BodyPaperObserved = true;
                }
            }


            ImGui::TreePop();
        }
    }
    ImGui::End();

}
