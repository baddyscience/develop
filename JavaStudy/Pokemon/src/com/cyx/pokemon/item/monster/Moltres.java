package com.cyx.pokemon.item.monster;

import com.cyx.pokemon.util.Tools;

/**
 * 火焰鸟
 */
public class Moltres extends Monster{

    public Moltres(int levelNumber) {
        super("火焰鸟", levelNumber);
        this.attack = Tools.getRandomNumber(80, 100, levelNumber);
        this.defense = Tools.getRandomNumber(70, 90, levelNumber);
        this.health = Tools.getRandomNumber(1400, 1800, levelNumber);
        this.currentHealth = this.health;
    }

    @Override
    public String getItemInformation() {
        return discovery ? "D" : "■";
    }
}
