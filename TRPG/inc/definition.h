#pragma once

#include <bits/stdc++.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

Role Yukino(740, 300);
Map M;

sf::View view;
float viewX = 0;
float viewY = 0;

enum class Locate{
    STARTROOM,
    BOOKROOM,
    KITCHEN,
    SLAVEROOM,
    AUDITORIUM
} NOWPOS;

bool LocateChange = true;

// Start Room
bool Lampdata = false;
bool Soupdata = false;
bool ReadPaperone = false;
bool ReadPapertwo = false;
bool BookRoomdata = false;
bool Kitchendata = false;
bool SlaveRoomdata = false;
bool Auditoriumdata = false;
// End Start Room 
