package com.cyx.pokemon.item.equipment;

import com.cyx.pokemon.util.Tools;

/**
 * 鞋子
 */
public class Shoe extends Equipment{

    public Shoe(int levelNumber) {
        super("鞋子", levelNumber);
        this.attack = 0;
        this.defense = Tools.getRandomNumber(10, 20, levelNumber);
        this.health = Tools.getRandomNumber(80, 100, levelNumber);
    }
}
