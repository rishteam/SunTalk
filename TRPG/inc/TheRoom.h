#include "imgui.h"
#include "imgui-SFML.h"

#include <map.h>
#include <role.h>

void SetupTheRoom(Map &M){

    M.init();
    Object ObjLamp(540,0,"lamp");
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

}

bool Soupdata = false;
bool ReadPaperone = false;
bool ReadPapertwo = false;
bool BookRoomdata = false;
bool Kitchendata = false;
bool SlaveRoomdata = false;
bool Auditoriumdata = false;

void RunTheRoom(sf::RenderWindow &window, Map &M, Role &role){

    switch (M.click(window)){
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

    ImGui::Begin("Bag");
    if( Soupdata ){
        if( ImGui::TreeNode("Soup") ){
            ImGui::TreePop();
        }
    }
    if( ReadPaperone ){
        if( ImGui::TreeNode("ParperOne") ){
            ImGui::Text("BookRoom - Kitchen - SoupRoom - SlaveRoom - Auditorium\n");
            ImGui::TreePop();
        }
    }
    if( ReadPapertwo ){
        if( ImGui::TreeNode("ParperTwo") ){
            ImGui::Text("if you want to back, drink this poisonous soup in an hour\n");
            ImGui::TreePop();
        }
    }
    if( BookRoomdata ){
        if( ImGui::TreeNode("BookRoom") ){
            ImGui::Text("It’s not locked, it should be easy to open.");
            ImGui::Button("Enter");
            ImGui::TreePop();
        }

    }
    if( Kitchendata ){
        if( ImGui::TreeNode("Kitchen") ){
            ImGui::Text("The door is all white, kitchen style sliding door without door handle");
            ImGui::Button("Enter");
            ImGui::TreePop();
        }

    }
    if( SlaveRoomdata ){
        if( ImGui::TreeNode("SlaveRoom") ){
            ImGui::Text("Although the door is locked, it is very fragile.");
            ImGui::Button("Enter");
            ImGui::TreePop();
        }

    }
    if( Auditoriumdata ){
        if( ImGui::TreeNode("Auditorium") ){
            ImGui::Text("Huge heavy iron door with small windows");
            ImGui::Button("Enter");
            ImGui::TreePop();
        }

    }
    ImGui::End();


}