package com.cyx.pokemon.item.equipment;

import com.cyx.pokemon.util.Tools;

/**
 * 头盔
 */
public class Helmet extends Equipment{

    public Helmet(int levelNumber) {
        super("头盔", levelNumber);
        this.attack = 0;
        this.defense = Tools.getRandomNumber(20, 30, levelNumber);
        this.health = Tools.getRandomNumber(100, 150, levelNumber);
    }
}
