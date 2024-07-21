package com.cyx.pokemon.item.equipment;

import com.cyx.pokemon.util.Tools;

/**
 * 护腿
 */
public class Leggings extends Equipment{

    public Leggings(int levelNumber) {
        super("护腿", levelNumber);
        this.attack = 0;
        this.defense = Tools.getRandomNumber(30, 40, levelNumber);
        this.health = Tools.getRandomNumber(150, 200, levelNumber);
    }
}
