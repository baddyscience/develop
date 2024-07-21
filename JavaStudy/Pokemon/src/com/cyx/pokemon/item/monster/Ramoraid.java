package com.cyx.pokemon.item.monster;

import com.cyx.pokemon.util.Tools;

/**
 * 铁炮鱼
 */
public class Ramoraid extends Monster{

    public Ramoraid(int levelNumber) {
        super("铁炮鱼", levelNumber);
        this.attack = Tools.getRandomNumber(60, 70, levelNumber);
        this.defense = Tools.getRandomNumber(50, 60, levelNumber);
        this.health = Tools.getRandomNumber(900, 1100, levelNumber);
        this.currentHealth = this.health;
    }

    @Override
    public String getItemInformation() {
        return discovery ? "C" : "■";
    }
}
