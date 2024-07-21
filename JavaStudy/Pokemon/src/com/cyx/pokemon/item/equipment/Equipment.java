package com.cyx.pokemon.item.equipment;

import com.cyx.pokemon.item.Item;
/**
 * 装备
 */
public abstract class Equipment extends Item {
    /**
     * 攻击力
     */
    protected int attack;
    /**
     * 防御力
     */
    protected int defense;
    /**
     * 生命值
     */
    protected int health;
    public Equipment(String name, int levelNumber) {
        super(name, levelNumber);
    }
    @Override
    public String getItemInformation() {
        return name + "：攻击=" + attack + " 防御=" + defense + " 生命值=" +
                health;
    }
}


