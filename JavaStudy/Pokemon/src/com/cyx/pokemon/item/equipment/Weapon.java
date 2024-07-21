package com.cyx.pokemon.item.equipment;

import com.cyx.pokemon.util.Tools;

/**
 * 武器
 */
public class Weapon extends Equipment{

    public Weapon(int levelNumber) {
        super("武器", levelNumber);
        this.attack = Tools.getRandomNumber(100, 150, levelNumber);
        this.defense = 0;
        this.health = Tools.getRandomNumber(250, 300, levelNumber);
    }
}
