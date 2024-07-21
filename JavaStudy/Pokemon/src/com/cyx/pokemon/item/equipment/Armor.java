package com.cyx.pokemon.item.equipment;

import com.cyx.pokemon.util.Tools;

/**
 * 铠甲
 */
public class Armor extends Equipment{

    public Armor(int levelNumber) {
        super("铠甲", levelNumber);
        this.attack = 0;
        this.defense = Tools.getRandomNumber(40, 50, levelNumber);
        this.health = Tools.getRandomNumber(200, 250, levelNumber);
    }
}
