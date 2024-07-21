package com.cyx.pokemon.item.equipment;

import com.cyx.pokemon.util.Tools;

/**
 * 手镯
 */
public class Bracelet extends Equipment{

    public Bracelet(int levelNumber) {
        super("手镯", levelNumber);
        this.attack = Tools.getRandomNumber(20, 30, levelNumber);
        this.defense = Tools.getRandomNumber(20, 20, levelNumber);
        this.health = Tools.getRandomNumber(100, 200, levelNumber);
    }
}
