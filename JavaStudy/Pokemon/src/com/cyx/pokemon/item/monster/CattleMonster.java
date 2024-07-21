package com.cyx.pokemon.item.monster;

import com.cyx.pokemon.util.Tools;

/**
 * 牛魔怪
 */
public class CattleMonster extends Monster{

    public CattleMonster(int levelNumber) {
        super("牛魔怪", levelNumber);
        this.attack = Tools.getRandomNumber(50, 60, levelNumber);
        this.defense = Tools.getRandomNumber(40, 50, levelNumber);
        this.health = Tools.getRandomNumber(700, 900, levelNumber);
        this.currentHealth = this.health;
    }

    @Override
    public String getItemInformation() {
        return discovery ? "B" : "■";
    }
}
