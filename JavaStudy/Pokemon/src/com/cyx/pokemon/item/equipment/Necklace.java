package com.cyx.pokemon.item.equipment;

import com.cyx.pokemon.util.Tools;

/**
 * 项链
 */
public class Necklace extends Equipment{

    public Necklace(int levelNumber) {
        super("项链", levelNumber);
        this.attack = Tools.getRandomNumber(25, 35, levelNumber);
        this.defense = Tools.getRandomNumber(25, 35, levelNumber);
        this.health = Tools.getRandomNumber(120, 180, levelNumber);
    }
}
