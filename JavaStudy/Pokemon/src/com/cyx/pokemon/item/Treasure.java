package com.cyx.pokemon.item;

import com.cyx.pokemon.util.Tools;

/**
 * 宝箱
 */
public class Treasure extends Item {

    public Treasure(int levelNumber) {
        super("宝箱", levelNumber);
    }

    /**
     * 开启宝箱能够获得一个物品
     * @return
     */
    public Item open(){
        return Tools.getRandomItem(levelNumber);
    }

    @Override
    public String getItemInformation() {
        return discovery ? "۞" : "■";
    }
}
