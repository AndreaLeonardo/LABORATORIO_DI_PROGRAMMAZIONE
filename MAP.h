//
// Created by Andrea on 06/07/2020.
//

#ifndef LAB_PROJECT_MAP_H
#define LAB_PROJECT_MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "findpath.h"


class Block {
private:
    int x, y, difficulty;
    sf::RectangleShape square;
    bool isWall = false;

public:
    Block(int x, int y, int d, sf::Texture &texture, sf::Vector2u Rect, int i, int j, bool isWall) : x(x), y(y),
                                                                                                     difficulty(d),
                                                                                                     isWall(isWall) {
        square.setSize(sf::Vector2f(32, 32));
        square.setPosition(x, y);
        square.setOrigin(16, 16);
        square.setTexture(&texture);
        square.setTextureRect(sf::IntRect(Rect.x * i, Rect.y * j, Rect.x, Rect.y));

    }

    Block() {}

    void draw(sf::RenderWindow &window) {
        window.draw(square);
    }

    void setPosition(int x, int y) {
        square.setPosition(x, y);
    }

    bool isWallBlock() {
        return isWall;
    }

    int getDiffculty() {
        return difficulty;
    }
};


void drawMap(sf::RenderWindow &window, MapSearchNode GoalNode) {

    sf::Texture MapTexture;
    MapTexture.loadFromFile("../sprite/map.png");
    sf::Vector2u textureSize = MapTexture.getSize();
    textureSize.x /= 17;
    textureSize.y /= 15;

    Block grassBlock(16, 16, 1, MapTexture, textureSize, 7, 1, false);
    Block whiteFlowerBlock(16, 16, 2, MapTexture, textureSize, 1, 2, false);
    Block yellowFlowerBlock(16, 16, 3, MapTexture, textureSize, 3, 4, false);
    Block purpleFlowerBlock(16, 16, 4, MapTexture, textureSize, 0, 4, false);
    Block obstacleBlock(16, 16, 5, MapTexture, textureSize, 8, 2, false);
    Block wallBlock(16, 16, 9, MapTexture, textureSize, 8, 0, true);
    Block goalBlock(GoalNode.x, GoalNode.y, 0, MapTexture, textureSize, 11, 6, false);
    Block ladderBlockL(16, 16, 7, MapTexture, textureSize, 4, 5, false);
    Block ladderBlockR(16, 16, 8, MapTexture, textureSize, 5, 5, false);


    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {

            if (world_map[j * MAP_HEIGHT + i] < 9 && GoalNode.x == i && GoalNode.y == j) {
                goalBlock.setPosition(16 + i * 32, 16 + j * 32);
                goalBlock.draw(window);
            } else if (grassBlock.getDiffculty() == world_map[j * MAP_HEIGHT + i]) {
                grassBlock.setPosition(16 + i * 32, 16 + j * 32);
                grassBlock.draw(window);
            } else if (whiteFlowerBlock.getDiffculty() == world_map[j * MAP_HEIGHT + i]) {
                whiteFlowerBlock.setPosition(16 + i * 32, 16 + j * 32);
                whiteFlowerBlock.draw(window);
            } else if (yellowFlowerBlock.getDiffculty() == world_map[j * MAP_HEIGHT + i]) {
                yellowFlowerBlock.setPosition(16 + i * 32, 16 + j * 32);
                yellowFlowerBlock.draw(window);
            } else if (purpleFlowerBlock.getDiffculty() == world_map[j * MAP_HEIGHT + i]) {
                purpleFlowerBlock.setPosition(16 + i * 32, 16 + j * 32);
                purpleFlowerBlock.draw(window);
            } else if (obstacleBlock.getDiffculty() == world_map[j * MAP_HEIGHT + i]) {
                obstacleBlock.setPosition(16 + i * 32, 16 + j * 32);
                obstacleBlock.draw(window);
            } else if (ladderBlockL.getDiffculty() == world_map[j * MAP_HEIGHT + i]) {
                ladderBlockL.setPosition(16 + i * 32, 16 + j * 32);
                ladderBlockL.draw(window);
            } else if (ladderBlockR.getDiffculty() == world_map[j * MAP_HEIGHT + i]) {
                ladderBlockR.setPosition(16 + i * 32, 16 + j * 32);
                ladderBlockR.draw(window);
            } else {
                wallBlock.setPosition(16 + i * 32, 16 + j * 32);
                wallBlock.draw(window);
            }

        }
    }
}



#endif //LAB_PROJECT_MAP_H