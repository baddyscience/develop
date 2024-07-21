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

    public int getAttack() {
        return attack;
    }

    public int getDefense() {
        return defense;
    }

    public int getHealth() {
        return health;
    }

    @Override
    public String getItemInformation() {
        return name + "：攻击=" + attack + " 防御=" + defense + " 生命值=" + health;
    }

    /**
     * 是否比其他装备好
     * @param other
     * @return
     */
    public boolean isBetter(Equipment other){
        //首先必须保证是同类型装备
        if(this.getClass() == other.getClass()){
            int total1 = this.attack + this.defense + this.health >> 1;
            int total2 = other.attack + other.defense + other.health >> 1;
            return total1 > total2;
        }
        return false;
    }
}
